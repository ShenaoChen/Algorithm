#include <iostream>

using namespace std;

const int N = 55;

char g[N][N];

void down(int i, int n, int m) {
    for (int j = 0; j < m; j++)
        if (g[i][j] == '*' && g[i + 1][j] == '.') 
            swap(g[i][j], g[i + 1][j]);
    if (i < n - 2)
        down(i + 1, n, m);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);
    for (int i = n - 2; i >= 0; i--)
        down(i, n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << g[i][j];
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}