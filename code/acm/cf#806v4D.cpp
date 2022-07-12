#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int N = 1e5 + 5;

string s[N];
int ans[N];

void solve() {
    map<string, bool> mp;
    int n;
    cin >> n;
    memset(ans, 0, sizeof (int) * (n + 1));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        mp[s[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < s[i].size(); j++) {
            string s1 = s[i].substr(0, j);
            string s2 = s[i].substr(j, s[i].size() - j);
            if (mp[s1] && mp[s2]) {
                ans[i]  = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}