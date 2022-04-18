#include <iostream>

using namespace std;

int main() {
    int n, tmp, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (i & 1)
            res ^= tmp;
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}