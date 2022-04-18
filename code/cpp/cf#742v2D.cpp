#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,s,n,tmp;
    cin>>t;
    while(t--){
        cin>>s>>n;
        tmp=s/n;
        for(int i=1;i<n;i++)
            printf("%d ",tmp);
        printf("%d\n",s-tmp*(n-1));
    }
    return 0;
}