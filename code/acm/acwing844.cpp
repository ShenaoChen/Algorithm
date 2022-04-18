#include<iostream>
#include<queue>

using namespace std;

typedef pair<int,int> PII;
const int N=105;

int n,m;
int g[N][N],d[N][N];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool vis[N][N];

bool check(int x,int y){
    return x>=0&&y>=0&&x<n&&y<m;
}
void bfs(){
    queue<PII> q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        PII tmp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=tmp.first+dir[i][0];
            int y=tmp.second+dir[i][1];
            if(check(x,y)&&!g[x][y]&&!vis[x][y]){
                vis[x][y]=1;
                d[x][y]=d[tmp.first][tmp.second]+1;
                q.push({x,y});
            }
        }
    }
    printf("%d\n",d[n-1][m-1]);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    bfs();
    return 0;
}