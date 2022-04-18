#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
const int N=3e5+5;
int a[N],sum[N];
vector<PII> add,query;
vector<int> alls;
int find(int x){
    int l=0,r=alls.size()-1,mid;
    while(l<r){
        mid=l+r>>1;
        if(alls[mid]>=x)
            r=mid;
        else
            l=mid+1;
    }
    return r+1;
}
int main(){
    int n,m,x,c,l,r;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&c);
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(auto item:add)
        a[find(item.first)]+=item.second;
    for(int i=1;i<N;i++)
        sum[i]=sum[i-1]+a[i];
    for(auto item:query)
        printf("%d\n",sum[find(item.second)]-sum[find(item.first)-1]);
    return 0;
}