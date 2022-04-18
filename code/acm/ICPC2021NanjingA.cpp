#include <iostream>

using namespace std;

const int N = 510;

void print(int dx, int dy) {
    if (dx < 0) cout << 'U';
    if (dx > 0) cout << 'D';
    if (dy < 0) cout << 'L';
    if (dy > 0) cout << 'R';
}

int main() {
    int n, x, y, px, py;
    cin >> n >> x >> y;
    int mid = n + 1 >> 1;
    for (int i = 1; i < n; i++) {
        if (x <= mid) {
            print(-1, 0);
            px = 1;
        }
        else{
            print(1, 0);
            px = n;
        }
    }
    for (int i = 1; i < n; i++) {
        if (y <= mid) {
            print(0, -1);
            py = 1;
        }
        else {
            print(0, 1);
            py = n;
        }
    }
    for (int i = 0; i < abs(px - x); i++)
        print(x - px, 0);
    for (int i = 0; i < abs(py - y); i++)
        print(0, y - py);
    return 0;
}