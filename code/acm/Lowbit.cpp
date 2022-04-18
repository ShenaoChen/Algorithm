#include<bits/stdc++.h>
#define lowbit(x) (x)&(-(x))
#define M 998244353
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
ll tree[N];
void add(int x,ll d){
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=d;
}
ll query(int x){
    int res;
    for(int i=x;i>0;i-=lowbit(i)){
        res+=tree[i];
        res%=M;
    }
    return res;
}
int main(){
    int t1,l,r;
    ll a,tmp1,tmp2;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        add(i,a);
    }
    cin>>m;
    while(m--){
        scanf("%d%d%d",&t1,&l,&r);
        if(t1==1){
            tmp1=query(l-1);
            tmp2=query(l);
            add(l,-lowbit(tmp2-tmp1));
        }
    }
    return 0;
}