#include <iostream>

using namespace std;

int main() {
    double vp, vd, t, f, c, x;
    int cnt = 0;
    cin >> vp >> vd >> t >> f >> c;
    if (vd <= vp) {
        cout << 0 << endl;
        return 0;
    }
    x = t * vp;
    x += x / (vd - vp) * vp;
    while (x < c) {
        cnt++;
        x += (x / vd + f) * vp;
        x += x / (vd - vp) * vp;
    }
    cout << cnt << endl;
    return 0;
}