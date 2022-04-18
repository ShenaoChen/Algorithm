#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int a,b,n;
    cin>>n;
    while(n--){
        scanf("%d%d",&a,&b);
        if((a+b)%2==1){
            printf("-1\n");
            continue;
        }
        if(a==0&&b==0)
            printf("0\n");
        if(a==b&&a!=0)
            printf("1\n");
        if(a!=b)
            printf("2\n");
    }
    return 0;
}