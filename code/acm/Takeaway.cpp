#include<bits/stdc++.h>
using namespace std;
int p[8]={0,7,27,41,49,63,78,108};
int main(){
    int t,n,a,sum;
    cin>>t;
    while(t--){
        sum=0;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&a);
            sum+=p[a];
        }
        if(sum>=120)
            sum-=50;
        else{
            if(sum>=89)
                sum-=30;
            else if(sum>=69)
                sum-=15;
        }
        printf("%d\n",sum);
    }
    return 0;
}