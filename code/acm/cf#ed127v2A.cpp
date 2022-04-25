#include <iostream>

using namespace std;

bool check(int x) {
    for (int i = 0; i <= x / 2 ; i++)
        for (int j = 0; j <= x / 3; j++) {
            if (2 * i + 3 * j == x)
                return true;

        }
    return false;
}

void solve() {
    string s;
    cin >> s;
    int cnt = 1;
    
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
            continue;
        }
        if (!check(cnt)) {
            cout << "NO" << endl;
            return;
        }
        cnt = 1;
    }
    if (check(cnt))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}