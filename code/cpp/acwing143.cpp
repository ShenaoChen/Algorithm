#include<iostream>

using namespace std;

const int N=1e5+5,M=3e5;
int a[N],son[M][2],idx;

void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int &s=son[p][x>>i&1];
        if(!s) s=++idx;
        p=s;
    }
}
int serch(int x){
    int p=0,res=0;   
    for(int i=30;i>=0;i--){
        int s=x>>i&1;
        if(!s){
            res+=1<<i;
            p=son[p][!s];
        }
        else
            p=son[p][s];
    }
    return res;
}

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        insert(a[i]);    
    }
    for(int i=0;i<n;i++){
        ans=max(ans,serch(a[i]));
    }
    printf("%d\n",ans);
    return 0;
}