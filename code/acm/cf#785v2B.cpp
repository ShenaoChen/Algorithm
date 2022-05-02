#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int pos[26];
bool st[26];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(pos, 0, sizeof pos);
        memset(st, 0, sizeof st);
        bool flag = true;
        string s;
        cin >> s;
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            
            if (i - pos[s[i] - 'a'] != cnt) {
                cout << "NO" << endl;
                flag = false;
                break; 
            }
            if (!st[s[i] - 'a']) {
                st[s[i] - 'a'] = true;
                cnt++;
            }
            pos[s[i] - 'a'] = i;
        }
        if (flag) cout << "YES" << endl;
    }
    return 0;
}