#include<iostream>
using namespace std;

int main(){
    int n,tmp,ans;
    cin>>n;
    while(n--){
        scanf("%d",&tmp);
        ans=0;
        while(tmp){
            ans+=tmp&1;
            tmp>>=1;
        }
        printf("%d ",ans);
    }
    return 0;
}