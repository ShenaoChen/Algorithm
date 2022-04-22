#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int a[N][32], sum[32];

void solve() {
    int n, k, tmp;
    cin >> n >> k;
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < n; i++) 
        memset(a[i], 0, sizeof (int) * 32);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < 32; j++) {
            if (tmp == 0) break;
            a[i][j] = tmp & 1;
            sum[j] += tmp & 1;
            tmp >>= 1;
        }
    }
    ll ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (n - sum[i] <= k) {
            ans += 1 << i;
            k -= (n - sum[i]);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}