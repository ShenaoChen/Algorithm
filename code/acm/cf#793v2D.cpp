#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, cnt = 0, pos = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
            pos = i;
        }
    }
    if (cnt == 0 || cnt & 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    pos = (pos + 1) % n;
    int i = (pos + 1) % n;
    while (i != pos) {
        cout << pos + 1 << ' ' << i + 1 << endl;
        while (s[i] != '1') {
            cout << i + 1 << ' ' << (i + 1) % n + 1 << endl;
            i = (i + 1) % n;
        }
        i = (i + 1) % n;
        //system("pause");
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}