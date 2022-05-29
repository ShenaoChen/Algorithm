#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 1;
        int pos = n / 2;
        for (int i = pos - 1; i >= 0; i--) {
            if(s[i] != s[pos])
                break;
            ans++;
        }
        for (int i = pos + 1; i < n; i++) {
            if(s[i] != s[pos])
                break;
            ans++;
        }
        cout << ans << endl;        
    }
    return 0;
}