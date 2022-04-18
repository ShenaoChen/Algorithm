#include<iostream>

using namespace std;

const int N=105;
char g[N][N];

void solve(int i,int j,int k){
    if(k==1)
        printf("%d %d %d %d %d %d\n",i,j,i,j+1,i+1,j);
    else if(k==2)
        printf("%d %d %d %d %d %d\n",i,j-1,i,j,i+1,j);
    else if(k==3)
        printf("%d %d %d %d %d %d\n",i-1,j,i,j,i,j+1);
    else
        printf("%d %d %d %d %d %d\n",i-1,j,i,j-1,i,j);
}

int main(){
    int t,n,m,ans;
    cin>>t;
    while(t--){
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            getchar();
            for(int j=1;j<=m;j++){
                scanf("%c",&g[i][j]);
                if(g[i][j]=='1')  ans+=3;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(g[i][j]=='1'){
                    if(i!=n&&j!=m)
                        solve(i,j,1),solve(i,j+1,2),solve(i+1,j,3);
                    else if(i!=n)
                        solve(i,j-1,1),solve(i,j,2),solve(i+1,j,4);
                    else if(j!=m)
                        solve(i-1,j,1),solve(i,j,3),solve(i,j+1,4);
                    else
                        solve(i-1,j,2),solve(i,j-1,3),solve(i,j,4);
                }
    }
    return 0;
}