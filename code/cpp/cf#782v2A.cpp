#include <iostream>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == b ) {
        for (int i = 1; i <= a; i++) 
            cout << "RB";
        cout << endl;
        return;
    }
    if (a > b) {
        if (b == 1) {
            for (int i = 1; i <= a / 2; i++)
                cout << 'R';
            cout << 'B';
            for (int i = a / 2 + 1; i <= a; i++)
                cout << 'R';
            cout << endl;
            return;
        }
        int t = a / (b + 1);
        int r = a % (b + 1);
        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= t; j++)
                cout << 'R';
            if (r-- > 0)
                cout << 'R';
            cout << 'B';
        }
        for (int i = 1; i <= t; i++)
            cout << 'R';
        cout << endl;
    }
    if (a < b) {
        if (a == 1) {
            for (int i = 1; i <= b / 2; i++)
                cout << 'B';
            cout << 'R';
            for (int i = b / 2 + 1; i <= b; i++)
                cout << 'B';
            cout << endl;
            return;
        }
        int t = b / (a + 1);
        int r = b % (a + 1);
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= t; j++)
                cout << 'B';
            if (r-- > 0)
                cout << 'B';
            cout << 'R';
        }
        for (int i = 1; i <= t; i++)
            cout << 'B';
        cout << endl;
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