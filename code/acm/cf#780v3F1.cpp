#include <iostream>

using namespace std;

void solve() {
    int n, res = 0;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (int i = 0; i < n -1; i++) {
        x = 0, y = 0;
        if (s[i] == '+') x++;
        else y++;
        for (int j = i + 1; j < n; j++) {
            if (s[j] == '+') x++;
            else y++;
            if (y - x >= 0 && (y - x) % 3 == 0) res++;
        }
    } 
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}