#include<bits/stdc++.h>
using namespace std;
int h[300];
int main(){
    int n,m,l,tmp;
    cin>>n>>m>>l;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&tmp);
            h[tmp]++;
        }
    }
    for(int i=0;i<l;i++)
        printf("%d ",h[i]);
    return 0;
}