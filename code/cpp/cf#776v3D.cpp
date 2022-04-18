#include<iostream>

using namespace std;

const int N = 2005;

int a[N], d[N];

void solve(){
    int n,tmp;
    int sum = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>tmp;
        a[tmp] = i;
    }
    for(int i = n; i > 0; i--){
        int index = a[i];
        d[i] = index % i;
        for(int j = 1; j < i; j++)
            a[j] = ((a[j] - d[i])  + i) % i;
    }
    for(int i = 1; i <= n; i++)
        cout<< d[i] << ' ';
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