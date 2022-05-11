#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a = s[0] - '0' + s[1] - '0' + s[2] - '0';
        reverse(s.begin(), s.end());
        int b = s[0] - '0' + s[1] - '0' + s[2] - '0';
        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}