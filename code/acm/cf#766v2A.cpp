#include<iostream>

using namespace std;

const int N = 55;

char g[N][N];

int solve(){
bool flag = false;
    int n, m, r, c;
    cin>>n >> m >> r >> c;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin>>g[i][j];
            if(g[i][j] == 'B')
                flag = true;
        }
    if(!flag)
        return -1;
    if(g[r][c] == 'B')
        return 0;
    for(int i = 1; i <= n; i++)
        if(g[i][c] == 'B')
            return 1;
    for(int i = 1; i <= m; i++)
        if(g[r][i] == 'B')
            return 1;
    return 2;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}