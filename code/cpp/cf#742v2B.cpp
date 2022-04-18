#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int x[N];
int main(){
    int t,a,b;
    for(int i=1;i<=N;i++)
        x[i]=x[i-1]^i;
    cin>>t;
    while(t--){
        scanf("%d%d",&a,&b);
        if(x[a-1]==b)
            printf("%d\n",a);
        else{
            if((x[a-1]^b)==a)
                printf("%d\n",a+2);
            else
                printf("%d\n",a+1);
        }
    }
    return 0;
}