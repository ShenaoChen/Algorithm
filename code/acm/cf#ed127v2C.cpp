#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int a[N];
ll sum[N];

void solve() {
    int n, tmp, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a, a + n + 1);
    for (int i = 1; i <= n; i++) 
        sum[i] = sum[i - 1] + a[i];
    ll ans = 0;
    int pos = n, cnt = 0;
    while (pos > 0) {
        if (sum[pos] + 1ll * cnt * pos > x) {
            pos--;
            continue;
        }
        int c = (x - sum[pos]) / pos;
        ans += (c - cnt + 1) * pos;
        cnt += c - cnt + 1;
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