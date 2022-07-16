#include <iostream>

using namespace std;

int main() {
    string s, str;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            str = s.substr(0, i) + s.substr(i + 1, n - i - 1);
            break;
        }
    }
    if(str.size() == 0) str = s.substr(0, n - 1);
    cout << str << endl;
    return 0;
}