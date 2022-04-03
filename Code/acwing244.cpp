#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], ans[N], tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int d) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += d;    
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

int find(int k) {
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (query(mid) < k) l = mid + 1;
        else r = mid;
    }
    return r;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        add(i, 1);
    for (int i = 2; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 0; i--) {
        ans[i] = find(a[i] + 1);
        add(ans[i], -1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}