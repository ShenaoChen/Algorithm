#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
    int t,n,cnt;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        for(int i=1;i<=n;i++)
            scanf("%d",b+i);
        for(int i=1;i<=n;i++){
            if(a[i]<b[1]){
                cnt=i-1;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(b[i]>a[1]){
                cnt=cnt<i-1?cnt:i-1;
                break;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}