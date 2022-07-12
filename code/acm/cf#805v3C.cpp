#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int index[N], mn[N], mx[N];
vector<int> alls;

int find(int x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(mn, 0, sizeof mn);
        memset(mx, 0, sizeof mx);
        alls.clear();
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> index[i];
            alls.push_back(index[i]);
        }
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        for (int i = 1; i <= n; i++) {
            int u = find(index[i]);
            if (mn[u] == 0) {
                mn[u] = mx[u] = i;
            }
            mx[u] = max(mx[u], i);
        }
        while (k--) {
            int a, b;
            cin >> a >> b;
            int fa = find(a), fb = find(b);
            if (alls[fa] != a || alls[fb] != b || mn[fa] > mx[fb] || mn[fa] == 0 || mn[fb] == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}