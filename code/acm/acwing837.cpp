#include<iostream>

using namespace std;

const int N=1e5+5;
int s[N],cnt[N];
int find(int x){
    if(s[x]!=x)
        s[x]=find(s[x]);
    return s[x];
}

int main(){
    int n,m,a,b;
    char op[5];
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        s[i]=i;
        cnt[i]=1;
    }
    while(m--){
        scanf("%s",op);
        if(op[0]=='C'){
            scanf("%d%d",&a,&b);
            a=find(a),b=find(b);
            if(a!=b){
                s[a]=b;
                cnt[b]+=cnt[a];
            }
        }
        else{
            if(op[1]=='1'){
                scanf("%d%d",&a,&b);
                printf(find(a)==find(b)?"Yes\n":"No\n");
            }
            else{
                scanf("%d",&a);
                printf("%d\n",cnt[find(a)]);
            }
        }
    }
    return 0;
}