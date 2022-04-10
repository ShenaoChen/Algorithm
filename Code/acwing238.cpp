#include <iostream>

using namespace std;

const int N = 30010;

int s[N], d[N], cnt[N];

int find(int x) {
    if (s[x] != x) {
        int root = find(s[x]);
        d[x] += d[s[x]];
        s[x] = root;
    }
    return s[x];
}

int main() {
    int m;
    for (int i = 1; i < N; i++) {
        s[i] = i;
        cnt[i] = 1;
    }
    cin >> m;
    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        
        if (*op == 'M') {
            a = find(a), b = find(b);
            if (a == b) continue;
            d[a] = cnt[b];
            cnt[b] += cnt[a];
            s[a] = b;
        }
        else {
            if (find(a) != find(b)) printf("-1\n");
            else printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
        }
    }
    return 0;
}