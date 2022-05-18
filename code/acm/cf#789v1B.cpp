#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;

int colnum[N], rownum[N];
bool col[N];

void solve() {
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    memset(colnum, 0, sizeof(int) * (n * m + 1));
    memset(rownum, 0, sizeof(int) * (n * m + 1));
    memset(col, 0, sizeof(bool) * (n * m + 1));
    int last = -1e8;
    for (int i = 0; i < n * m; i++) {
        int u = s[i] - '0';
        if (i > 0) colnum[i] = colnum[i - 1];
        if (i >= m) rownum[i] = rownum[i - m];
        if (u == 1) {
            if (col[i % m] == false) {
                colnum[i]++;
                col[i % m] = true;
            }
            last = i;
        }
        if (i - last < m) rownum[i]++;
        printf("%d ", rownum[i] + colnum[i]);
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}