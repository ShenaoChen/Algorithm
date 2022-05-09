#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0, part = 0;
        char last = -1;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1])
                ans++;
            else {
                if (s[i] != last) {
                    part++;
                    last = s[i];
                }
            }
        }
        part = max(part, 1);
        cout << ans << ' ' << part << endl;
    }
    return 0;
}