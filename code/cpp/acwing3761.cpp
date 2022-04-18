#include<iostream>
#include<cstring>

using namespace std;

const int N=2e5+5;
int cnt[N],h[N];

void solve(int n){
    for(int i=1;i<=n;i++){
        if(cnt[i]==1){
            printf("%d\n",h[i]);
            return ;
        }
    }
    printf("-1\n");
}

int main(){
    int t,n,tmp;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        memset(cnt,0,sizeof(int)*(n+1));
        for(int i=1;i<=n;i++){
            scanf("%d",&tmp);
            cnt[tmp]++;
            h[tmp]=i;
        }
    }

    return 0;
}