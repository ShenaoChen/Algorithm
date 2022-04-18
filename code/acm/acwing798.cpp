#include<iostream>
using namespace std;
int a[1005][1005],b[1005][1005];
int main(){
    int n,m,q,tmp,x1,x2,y1,y2,c;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&tmp);
            b[i][j]+=tmp;
            b[i+1][j]-=tmp;
            b[i][j+1]-=tmp;
            b[i+1][j+1]+=tmp;
        }
    }
    while(q--){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        b[x1][y1]+=c;
        b[x2+1][y1]-=c;
        b[x1][y2+1]-=c;
        b[x2+1][y2+1]+=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j];
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}