#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int a[N];

void solve() {
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] > 3) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] - a[i - 1] == 3) {
            if (!flag) {
                cout << "NO" << endl;
                return;
            }
            a[i]--;
            flag = false;
        }
        else if (a[i] - a[i - 1] == 2) {
            if (flag) flag = false;
            else a[i]--;
        }
    }
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