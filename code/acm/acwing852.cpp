#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N=2010,M=10010;

int n,m;
int h[N],e[M],w[M],ne[M],idx;
int dist[N],cnt[N];
bool st[N];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    queue<int> q;
    q.push(1);
    st[1]=true;

    while(!q.empty()){
        int t=q.front();
        q.pop();
        st[t]=false;

        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;

                if(cnt[j]>n) return true;

                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    
    return false;
}

int n,m;


int main(){
    memset(h,0,sizeof h);
    int a,b,c;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }

    if(spfa()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}