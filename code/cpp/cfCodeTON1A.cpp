#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n, tmp;
    cin >> n;
    int l, r, mn = 2e9, mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        if(tmp < mn) mn = tmp, l = i;
        if(tmp > mx) mx = tmp, r = i;
    }
    cout << l << ' ' << r << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}