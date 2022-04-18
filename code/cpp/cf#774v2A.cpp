#include<iostream>  

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, s;
        cin>>n>>s;
        cout<<s / (n * n)<<endl;
    }
    return 0;
}