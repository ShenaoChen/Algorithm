#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,m,t,mx,sum;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>m;
        sum=a+b+c;
        mx=max(a,max(b,c));
        if(sum-3>=m&&mx-(sum-mx)<=m+1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}