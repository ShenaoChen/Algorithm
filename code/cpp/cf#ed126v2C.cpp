#include <iostream>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

int n, h[N], tmp[N];

bool check(ll x, int k) {
    ll a = (x + 1) / 2, b = x / 2;
    for (int i = 1; i <= n; i++) {
        ll t = min(b, (ll)((h[i] + k) / 2));
        b -= t, tmp[i] = (h[i] + k) - 2 * t;
    }
    for (int i = 1; i <= n; i++)
        a -= tmp[i];
    return a >= 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
            mx = max(mx, h[i]);
        }
        for (int i = 1; i <= n; i++) {
            h[i] = mx - h[i];
        }
        ll l = 0, r = 1ll * n * mx * 2;
        while (l < r) {
            ll mid = l + r >> 1;
            if (check(mid, 0) || check(mid, 1)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}