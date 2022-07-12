#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        if (m < 10) {
            cout << m - 1 << endl;
        }
        else {
            int i = 1; 
            while (i * 10 <= m) i *= 10;
            cout << m - i << endl;
        }
    }
    return 0;
}