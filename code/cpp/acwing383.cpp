#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;

struct node{
    int id, d, x;
    node(int _id, int _d, int _x){
        id = _id, d = _d, x = _x;
    }
    bool operator < (const node &a) const {
        return d > a.d;
    }
};

int s, t;
int h[N], e[N], ne[N], w[N], idx; 
int dis[N][2];
int cnt[N][2];
bool st[N][2];

void add(int a, int b, int c){
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    priority_queue<node> q;
    q.push({s, 0, 0});
    while(!q.empty()){
        auto [v, d, x] = q.top();
        q.pop();
        if(st[v][x]) continue;
        st[v][x] = true;
        for(int i = h[v]; i != -1; i = ne[i]){
            int u = e[i];
            if(dis[u][0] > dis[v][x] + w[i]){
                dis[u][1] = dis[u][0];
                cnt[u][1] = cnt[u][0];
                q.push({u, dis[u][1], 1});
                dis[u][0] = dis[v][x] + w[i];
                cnt[u][0] = cnt[v][x];
                q.push({u, dis[u][0], 0});
            }
            else if(dis[u][0] == dis[v][x] + w[i]){
                cnt[u][0] += cnt[v][x];
            }
            else if(dis[u][1] > dis[v][x] + w[i]){
                dis[u][1] = dis[v][x] + w[i];
                cnt[u][1] = cnt[v][x];
                q.push({u, dis[u][1], 1});
            }
            else if(dis[u][1] == dis[v][x] + w[i]){
                cnt[u][1] += cnt[v][x];
            }
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    idx = 0;
    memset(h, -1, sizeof h);
    memset(dis, 0x3f, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    cin>>s>>t;
    dis[s][0] = 0;
    cnt[s][0] = 1;
    bfs();
    int ans = cnt[t][0];
    if(dis[t][1] == dis[t][0] + 1)
        ans += cnt[t][1];
    cout<< ans <<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}