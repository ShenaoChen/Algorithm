#include<iostream>

using namespace std;

const int N=50005;
int s[N],d[N];
int find(int x){
    if(s[x]!=x){
        int t=find(s[x]);
        d[x]+=d[s[x]];
        s[x]=t;
    }
    return s[x];
}

int main(){
    int n,m,k,x,y,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) s[i]=i;
    while(m--){
        scanf("%d%d%d",&k,&x,&y);
        if(x>N||y>N){
            ans++;
            continue;
        }
        int sx=find(x),sy=find(y);
        if(k==1){
            if(sx==sy&&(d[x]-d[y])%3!=0) ans++;
            else if(sx!=sy){
                s[sx]=sy;
                d[sx]=d[y]-d[x];
            }
        }
        else{
            if(sx==sy&&(d[x]-d[y]-1)%3!=0) ans++;
            else if(sx!=sy){
                s[sx]=sy;
                d[sx]=d[y]-d[x]+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}