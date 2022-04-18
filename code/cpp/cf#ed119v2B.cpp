#include<iostream>

using namespace std;

typedef long long ll;
ll a[10];

int main(){
    int t;
    cin>>t;
    while(t--){
        ll w, h;
        cin>>w>>h;
        ll tmp, k;
        for(int i = 1; i <= 4; i++){
            cin>>k>>a[i];
            for(int j = 1; j < k; j++)
                cin>>tmp;
            a[i] = tmp - a[i];
        }
        ll ans = max(max(a[1],a[2]) * h, max(a[3],a[4]) * w) ;
        cout<< ans <<endl;
    }
    return 0;
}