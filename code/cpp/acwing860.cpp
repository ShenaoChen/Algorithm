#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c){
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j] && dfs(j, 3-c) || color[j] == c) return false;
    }
    return true;
}

int main(){
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    while(m -- ){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = true;

    for(int i = 1; i <= n; i++){
        if(!color[i] && !dfs(i, 1)){
            flag = false;
            break;
        }
    }

    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}