#include<bits/stdc++.h>
using namespace std;
int sum[605][605],tmp,ans;
int main(){
    int n,L,r,t,x1,x2,y1,y2;
    cin>>n>>L>>r>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&tmp);
            sum[i][j]=tmp+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            x1=j-r>1?j-r:1;
            x2=j+r<n?j+r:n;
            y1=i-r>1?i-r:1;
            y2=i+r<n?i+r:n;
            if(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<=t*(x2-x1+1)*(y2-y1+1))
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}