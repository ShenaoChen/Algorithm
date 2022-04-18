#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

typedef pair<int, int> PII;

map<PII, bool> st;
vector<PII> v;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool check(int x, int y){
    return abs(x) <= 1e6 && abs(y) <= 1e6;
}

void solve(PII a){
    queue<PII> q; 
    q.push(a);
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(st[{x, y}] == true) continue;
        if(!st[{x, y}]){
            cout<<x<<' '<<y<<endl;
            return;
        }
        for(int i = 0; i < 4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(check(dx, dy))
                q.push({dx, dy});
        }
    }
}

int main(){
    int n, x, y;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        st[{x, y}] = true;
        v.push_back({x, y});
    }
    for(int i = 0; i < n; i++){
        solve(v[i]);
    }
    return 0;
}