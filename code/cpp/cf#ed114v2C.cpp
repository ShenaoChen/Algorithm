#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
int main(){
    int n,m,l,r,mid;
    ll sum=0,ans,tmp1,tmp2,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
        sum+=a[i];
    }
    sort(a,a+n);
    //for(int i=0;i<n;i++)
      //  cout<<a[i]<<' ';
    cout<<endl;
    cin>>m;
    while(m--){
        scanf("%lld%lld",&x,&y);
        l=0,r=n-1;
        while(l<r){
            mid=(l+r)>>1;
            if(a[mid]>=x)
                r=mid;
            else
                l=mid+1;
        }
        //cout<<a[r]<<' ';
        tmp1=max(0ll,x-a[r])+max(0ll,y-(sum-a[r]));
        if(r>0)
            tmp2=max(0ll,x-a[r-1])+max(0ll,y-(sum-a[r-1]));
        else
            tmp2=tmp1;
        ans=min(tmp1,tmp2);
        printf("%lld\n",ans);
    }
    return 0;
}