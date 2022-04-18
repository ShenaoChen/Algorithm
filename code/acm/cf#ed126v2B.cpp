#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int mod = 32768, N = mod + 5;

int res[N];
bool st[N];

void bfs(int x) {
    if (x == 0 || res[x]) return;
    memset(st, 0, sizeof st);
    queue<PII> q;
    q.push({x, 0});
    while(!q.empty()) {
        auto [v, d] = q.front();
        q.pop();
        //st[v] = false;
        int a = (v + 1) % mod;
        int b = 2 * v % mod;
        if (a == 0 || b == 0) {
            res[x] = d + 1;
            return;
        }
        if (!st[a]) {
            q.push({a, d + 1});
            st[a] = true;
        }
        if (!st[b]) {
            q.push({b, d + 1});
            st[b] = true;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int tmp;
        cin >> tmp;
        bfs(tmp);
        cout << res[tmp] << ' ';
    }
    return 0;
}