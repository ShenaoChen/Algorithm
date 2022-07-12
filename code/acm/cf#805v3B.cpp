#include <iostream>
#include <cstring>

using namespace std;

bool st[26];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(st, 0, sizeof st);
        string s;
        cin >> s;
        int m = 0, n = s.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            if (!st[s[i] - 'a']) {
                st[s[i] - 'a'] = true;
                m++;
            }
            if (m == 4) {
                ans++;
                m = 1;
                memset(st, 0, sizeof st);
                st[s[i] - 'a'] = true;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}