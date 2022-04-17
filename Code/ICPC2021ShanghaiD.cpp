#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

void solve() {
    ll p, q;
    cin >> p >> q;
    if (p * p - 4 * q * q < 0) {
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    ll tmp = sqrt(p * p - 4 * q * q);
    if (tmp * tmp != p * p - 4 * q * q) {
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    cout << p + tmp << ' ' << 2 * q << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}