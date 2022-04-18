#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b,l,r;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a<b){
            int t=a;
            a=b;
            b=t;
        }
        l=(a-b)/2;
        r=a+b-l;
        if((a+b)%2==1){
            printf("%d\n",r-l+1);
            for(int i=l;i<=r;i++)
                printf("%d ",i);
        }
        else{
            printf("%d\n",(r-l)/2+1);
            for(int i=l;i<=r;i+=2)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}