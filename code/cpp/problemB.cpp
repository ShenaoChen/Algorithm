#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+5;
int  miu[N],vis[N],sum[N];
int a,b,c,d,k,t;
void getmiu(){
    for(int i=1;i<N;i++)
        miu[i]=1,vis[i]=0;
    for(int i=2;i<=N;i++){
        if(vis[i])continue;
        miu[i]=-1;
        for(int j=2*i;j<=N;j+=i){
            vis[j]=1;
            if((j/i)%i==0)
                miu[j]=0;
            else
                miu[j]*=-1;
        }
    }
    for(int i=1;i<=N;i++)
        miu[i]+=miu[i-1];
}
ll f(int n,int m){
    ll res=0;
    if(n>m)swap(n,m);
    for(int l=1,r=0;l<=n;l=r+1){
        r=min(n/(n/l),m/(m/l));
        res+=1ll*(miu[r]-miu[l-1])*(n/l)*(m/l);
    }
    return res;
}
int main(){
    scanf("%d",&t);
    getmiu();
    while(t--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        //a/=k,b/=k,c/=k,d/=k;
        //printf("%lld\n",f((a-1)/k,(c-1)/k)+f(b/k,d/k)-f((a-1)/k,d/k)-f(b/k,(c-1)/k));
        printf("%lld\n", f(b / k, d / k) - f((a - 1) / k, d / k) - f(b / k, (c - 1) / k) + f((a - 1) / k, (c - 1) / k));
    }
    return 0;
}
