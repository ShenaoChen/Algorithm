#include<iostream>

using namespace std;

int main(){
    int t,n,m,tmp,sum,M,cnt;
    cin>>t;
    while(t--){
        cnt=0,sum=0,M=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&tmp);
                M=min(M,abs(tmp));
                if(tmp<0){
                    cnt++;
                    tmp=-tmp;
                }
                sum+=tmp;
            }
        }
        if(cnt&1==1)
            sum-=2*M;
        printf("%d\n",sum);
    }
    return 0;
}