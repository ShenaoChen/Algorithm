#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int cnt[2] = {0};
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            cnt[s[i] - '0']++;
            if (s[i] != s[i + 1] && ((cnt[0] & 1) || (cnt[1] & 1))) {
                if (cnt[0] <= cnt[1]) cnt[0]++, cnt[1]--;
                else cnt[1]++, cnt[0]++;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}