#include <iostream>

using namespace std;

void solve() {
    int n;
    string s, a, b;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == '2')
            a += '1', b += '1';
        if(s[i] == '0')
            a += '0', b += '0';
        if(s[i] == '1'){
            a += '0', b += '1';
            a += s.substr(i + 1); 
            break;
        }
    }
    while(b.size() < n) b += '0';
    cout << a << endl;
    cout << b << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}