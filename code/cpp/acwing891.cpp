#include <iostream>

using namespace std;

int main() {
    int n, tmp, res = 0;
    cin >> n;
    while (n--) {
        cin >> tmp;
        res ^= tmp;
    }
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}