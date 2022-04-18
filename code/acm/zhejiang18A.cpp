#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll b=0,r=0,t;
    for(int i=1;i<=5;i++){
        cin>>t;
        b+=t;
    }
    for(int i=1;i<=5;i++){
        cin>>t;
        r+=t;
    }
    if(b>=r)
        cout<<"Blue"<<endl;
    else
        cout<<"Red"<<endl;
    return 0;
}