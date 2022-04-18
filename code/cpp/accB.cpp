#include <iostream>
#include <cstring>

using namespace std;

const int N = 210;

int a[N];
bool st[N];

void solve(){
    int n, k;
    int ans = 0;
    cin>>n>>k;
    memset(st, 0, sizeof st);
    for(int i = 0; i < k; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++){
        ans = i;
        bool flag = true;
        for(int j = 0; j < k; j++){
            st[max(a[j] - (i - 1), 1)] = true;
            st[min(a[j] + (i - 1), n)] = true;
        }
        for(int j = 1; j <= n; j++){
            if(st[j] == false)
                flag = false;
        }
        if(flag){
            cout << ans << endl;
            return;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}