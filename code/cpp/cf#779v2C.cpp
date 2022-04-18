#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int c[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,pos = -1;
        bool flag = true;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin  >> c[i];
            if (c[i] == 1)
                pos = i;
        }
        if (pos == -1) {
            cout << "No" <<endl;
            continue;
        }
        for (int i = (pos + 1) % n, lim = 2, pre = c[pos]; i != pos; i = (i + 1) % n) {
            if (c[i] > lim || c[i] < 2){
                flag =false;
                break;
            }
            lim = c[i] + 1;
        }
        if (flag) cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}