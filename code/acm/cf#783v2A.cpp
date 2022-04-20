#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n < m) swap(n, m);
        if (m == 1 && n > 2) {
            cout << -1 << endl;
            continue;
        }
        cout << 1ll * 2 * (m - 1) + 1ll * 2 * (n - m) - ((n - m) & 1) << endl;
    }
    return 0;
}