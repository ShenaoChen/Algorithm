#include <iostream>

using namespace std;

int a[60];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += a[i] - mn;
        cout << ans << endl;
    }
    return 0;
}