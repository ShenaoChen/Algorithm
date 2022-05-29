#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n, k, q;
    while (t--) {
        scanf("%d%d%d", &n, &k, &q);
        k %= 2 * n;
        if (q % 2) {
            if (q + k <= n) {
                cout << q + k << endl;
                continue;
            }
            else {
                k -= (n - q);
                q = n;
            }
            if (n >= k) {
                cout << n + 1 - k << endl;
                continue;
            }
            else {
                k -= n;
                q = 1;
            }
            cout << k << endl;
        }
        else {
           if (q - k >= 1) {
               cout << q - k << endl;
               continue;
            }
            else {
                k -= (q - 1);
                q = 1;
            }
            if (k <= n) {
                cout << k << endl;
                continue;
            }
            else {
                k -= n;
                q = n;
            }
            cout << q - k + 1 << endl;
        }
    }
    return 0;
}