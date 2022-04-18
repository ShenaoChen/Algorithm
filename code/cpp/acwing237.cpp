#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 5;

int n, cnt;
int s[N];
unordered_map<int, int> h;

struct Query {
    int x, y, e;
} query[N];

int find(int x) {
    if (s[x] != x) s[x] = find(s[x]);
    return s[x];
}

int get(int x) {
    if (h.count(x) == 0) h[x] = cnt++;
    return h[x];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        bool flag = false;
        cnt = 1;
        h.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x, y, e;
            scanf("%d%d%d", &x, &y, &e);
            x = get(x), y = get(y);
            query[i] = {x, y, e};
        }
        for (int i = 1; i <= cnt; i++) s[i] = i;
        for (int i = 1; i <= n; i++) {
            auto [a, b, e] = query[i];
            if (e == 0) continue;
            a = find(a), b = find(b);
            s[a] = b;
        }
        for (int i = 1; i <= n; i++) {
            auto [a, b, e] = query[i];
            if (e == 1) continue;
            a = find(a), b = find(b);
            if (a == b) {
                flag = true;
                break;
            }
        }
        if (flag) puts("NO");
        else puts("YES");
    }
    return 0;
}