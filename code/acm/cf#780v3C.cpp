#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int dp[N][2], pos[26];

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    memset(pos, -0x3f, sizeof pos);
    for (int i = 1; i <= n; i++) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        int c = pos[s[i] - 'a'];
        if (c <= 0) dp[i][0] = inf;
        else dp[i][0] = min(dp[c - 1][0], dp[c - 1][1]) + i - c - 1;
        pos[s[i] - 'a'] = i;
        // cout << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}