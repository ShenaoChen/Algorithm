#include<bits/stdc++.h>
using namespace std;
int a[55],b[55];
void solve(){
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++){
        if(a[i]*3<b[i]){
            cout<<i<<endl;
            return ;
        }
    }
    cout<<-1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}