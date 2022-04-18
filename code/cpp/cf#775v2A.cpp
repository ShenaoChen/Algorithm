#include<iostream>

using namespace std;

int a[105];

void solve(){
    int n, ans = 0;
    int i, j;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(i = 0; i < n; i++)
        if(a[i] == 0)
            break;
    for(j = n - 1; j >= 0; j--)
        if(a[j] == 0)
            break;
    cout<<max(0, j - i + 2)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}