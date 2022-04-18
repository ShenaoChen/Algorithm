#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct cave{
    int _num;
    ll _min;
    cave(int num,ll m):_num(num),_min(m){}
};
bool cmp(cave x,cave y){
    return x._min<y._min;
}
vector<cave>a;
ll tmp[N];
int main(){
    int t,n,num;
    ll m,ans,power,s;
    cin>>t;
    while(t--){
        a.clear();
        scanf("%d",&n);
        while(n--){
            m=0;
            scanf("%d",&num);
            for(int i=1;i<=num;i++){
                scanf("%lld",tmp+i);
                tmp[i]-=i-2;
                if(tmp[i]>m)
                    m=tmp[i];
            }
            a.push_back(cave(num,m));

        }
        sort(a.begin(),a.end(),cmp);
        power=ans=a[0]._min;
        for(int i=1;i<a.size();i++){       
            power+=a[i-1]._num;
            if(power<a[i]._min){
                ans+=a[i]._min-power;
                power=a[i]._min;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}