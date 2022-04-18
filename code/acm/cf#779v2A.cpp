#include <iostream>

using namespace std;

int main() {
    string s;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int res = 0;
        for (int i = 0, j = 0; i < n && j < n; j++) {
            if (i == 0) 
                while (s[i] == '1') i++;
            if (s[j] == '1') 
                continue;
            if (j - i == 1) res += 2;
            if (j - i == 2) res += 1;
            i = j;
        }
        cout << res << endl;
    }
    return 0;
}