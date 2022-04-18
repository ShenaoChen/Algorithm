#include<iostream>

using namespace std;

const int N = 10010;

bool st[N];

int d(int n){
    int res = n;
    while(n){
        res += n %10;
        n /= 10;
    }
    return res;
}

int main(){
    for(int i = 1; i < N; i++){
        for(int j = d(i); j < N; j = d(j)){
            st[j] = true;
        }
    }
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        if(!st[i])
            cout<<i<<endl;
    }
    return 0;
}