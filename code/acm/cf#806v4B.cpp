#include <iostream>
#include <cstring>

using namespace std;

bool st[26];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(st, 0, sizeof st);
        int n, ans = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            int u = s[i] - 'A';
            if (!st[u]) {
                st[u] = true;
                ans++;
            }
        }
        ans += n;
        cout << ans << endl;
    }
    return 0;
}