#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    ll cur = 0, ans = 1e18;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cur += abs(a[i] - a[i + 1]);
    int t = 2; 
    while (t--) {
        int mn = abs(a[0] - 1);
        ans = min(ans, cur + abs(a[0] - x) + (x - 1));
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, cur + abs(a[i] - x) + abs(a[i + 1] - x) - abs(a[i] - a[i + 1]) + mn);
            ans = min(ans, cur + abs(a[i] - x) + abs(a[i + 1] - 1) - abs(a[i] - a[i + 1]) + (x - 1));
            mn = min(mn, abs(a[i] - 1) + abs(a[i + 1] - 1) - abs(a[i] - a[i + 1]));
        }
        ans = min(ans, cur + mn + abs(a.back() - x));
        reverse(a.begin(), a.end());
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
