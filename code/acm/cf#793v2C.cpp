#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n, tmp, ans = 0;
    bool flag = true;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        mp[tmp]++;
    }
    int s = 0, t = 0;
    for (auto [x, cnt] : mp) {
        if (cnt > 1) t++;
        else s++;
    }
    ans = t + (s + 1) / 2;
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