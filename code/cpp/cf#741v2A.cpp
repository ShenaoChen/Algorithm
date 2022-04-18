#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r,n;
    
    cin>>n;
    while(n--){
        scanf("%d%d",&l,&r);
        printf("%d\n",(r>=2*l?r%(r/2+1):r%l));
    }
    return 0;
}