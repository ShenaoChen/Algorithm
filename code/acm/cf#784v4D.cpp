#include <iostream>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int sum = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            if (sum == 1 || sum != 0 && cnt1 == sum || sum != 0 && cnt2 == sum) {
                cout << "NO" << endl;
                return;
            }
            sum = 0, cnt1 = 0, cnt2 = 0;
            continue;
        }
        if (s[i] == 'R') cnt1++;
        if (s[i] == 'B') cnt2++;
        sum++;
    }
    if (sum == 1 || sum != 0 && cnt1 == sum || sum != 0 && cnt2 == sum)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}