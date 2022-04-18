#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int g[N][N], dp[N][N];
int n, m, ans;

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y){
    if(!check(x, y)) return 0;
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(check(nx, ny) && g[nx][ny] < g[x][y])
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            dfs(i, j);
            ans = max(ans, dp[i][j]);
        }
    cout << ans << endl;
    return 0;
}