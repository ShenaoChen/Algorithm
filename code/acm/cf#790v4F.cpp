#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solve() {
    unordered_map<int, int> m;
    vector<int> a;
    int n, k, tmp;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        m[tmp]++;
    }
    for (auto [x, cnt] : m)
        if (cnt >= k) a.push_back(x);
    sort(a.begin(), a.end());
    n = a.size();
    int mx = 0, l = 0, r = 0, al, ar;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] != 1) {
            if (r - l + 1 >= mx) {
                mx = r - l + 1;
                al = l, ar = r;
                l = i + 1;
            }
        }
        r = i + 1;
    }
    if (r - l + 1 >= mx) {
        mx = r - l + 1;
        al = l, ar = r;
    }
    if (a.size() == 0) cout << -1 << endl;
    else cout << a[al] << ' ' << a[ar] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}