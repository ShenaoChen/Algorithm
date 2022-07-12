#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int tr[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int n) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i]++;
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve() {
    int n, tmp;
    cin >> n;
    ll ans = 0;
    memset(tr, 0, sizeof tr);
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (tmp < i) {
            ans += query(tmp - 1);
            add(i, n);
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