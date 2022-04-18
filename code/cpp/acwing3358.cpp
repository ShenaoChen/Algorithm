#include <iostream>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), ans = 1;
    for(int i = 0, j = 0; i <= n; i++){
        if(i == n){
            ans++;
            i = 0;
        }
        if(s[i] == t[j]) j++;
        if(j >= m) break;
    }
    cout << ans << endl;
    return 0;
}