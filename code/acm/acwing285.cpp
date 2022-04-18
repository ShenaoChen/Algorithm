#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int e[N], ne[N], h[N], w[N], idx;
int dp[N][2];
bool st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++, st[b] = true;
}

void dfs(int root){
    for(int i = h[root]; i !=  -1; i = ne[i]){
        int j = e[i];
        dfs(j);
        dp[root][0] += max(dp[j][0], dp[j][1]);
        dp[root][1] += dp[j][0];
    }
    dp[root][1] += w[root];
}

int main(){
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        add(b, a);
    }
    int root;
    for(int i = 1; i <= n; i++)
        if(!st[i]) {
            root = i;
            break;
        }
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}