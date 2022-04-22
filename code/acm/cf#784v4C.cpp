#include <iostream>

using namespace std;

const int N = 100;

int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    int last = (a[1] & 1);
    for (int i = 3; i <= n; i += 2) {
        if ((a[i] & 1) != last) {
            cout << "NO" << endl;
            return;
        }
    }
    last = a[2] & 1;
    for (int i = 4; i <= n; i += 2) {
        if ((a[i] & 1) != last) {
            cout << "NO" << endl;
            return;
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