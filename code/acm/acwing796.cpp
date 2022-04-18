#include<iostream>
using namespace std;
int sum[1005][1005];
int main(){
    int n,m,q,tmp,x1,x2,y1,y2;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&tmp);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tmp;
        }
    }
    while(q--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
    }
    return 0;
}