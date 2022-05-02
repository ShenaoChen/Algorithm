#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        if (n == 1) {
            cout << "Bob " << s[0] - 'a' + 1 << endl;
            continue;
        }
        else if ((n & 1) == 0) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += s[i] - 'a' + 1;
            cout << "Alice " << sum << endl;
            continue;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n - 1; i++) cnt1 += s[i] - 'a' + 1;
        for (int i = 1; i < n; i++) cnt2 += s[i] - 'a' + 1;
        cout << "Alice " << max(cnt1 - (s[n - 1] - 'a' + 1), cnt2 - (s[0] - 'a' + 1)) << endl;
    }
    return 0;
}