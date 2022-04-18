#include <iostream>

using namespace std;

void solve(){
    int n, tmp = 1;
    cin>>n;
    while(--n){
        tmp *= 3;
        if(tmp > 1e9){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 1; i <= tmp; i *= 3)
        cout<< i <<' ';
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}