#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int a[N];

void solve(){
    int n;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) cnt++;
    }
    if(cnt == 0 || n == 1){
        cout << "YES" << endl;
        return;
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] == 1){
            cout << "NO" <<endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}