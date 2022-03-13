#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

int d[N];
int cnt1[N], cnt2[N];
vector<int> g[N];

int s, t;

void bfs(){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(d[u] + 1 < d[v]){
                cnt1[v] = cnt2[v] = 0;
                d[v] = d[u] + 1;
                q.push(v);
            }
            if(d[u] + 1 == d[v])
                cnt1[v] = (cnt1[v] + cnt1[u]) % mod;
            if(d[v] + 1 == d[u])
                cnt2[u] = (cnt2[u] + cnt2[v]) % mod;
            if(d[v] == d[u])
                cnt2[u] = (cnt2[u] + cnt1[v]) % mod;
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m>>s>>t;
    for(int i = 1; i <= n; i++){
        d[i] = inf;
        g[i].clear();
    }
    d[s] = 0, cnt1[s] = 1, cnt2[s] = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
    cout<<(cnt1[t] + cnt2[t]) % mod<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
