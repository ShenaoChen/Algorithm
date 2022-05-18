#include <iostream>

using namespace std;

const int N = 2e5 + 5;

int s[N], cnt[N];
int a[N], b[N];

int find(int x) {
    if (s[x] != x)
        s[x] = find(s[x]);
    return s[x];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        s[i] = i, cnt[i] = 1;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        int x = find(a[i]);
        int y = find(b[i]);
        if (x != y) {
            s[x] = y;
            cnt[y] += cnt[x];
        }
    }
    long long ans = 0;
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (s[i] == i && cnt[i] > 1) {
            int tmp = cnt[i];
            for (int j = 0; j < tmp / 2; j++) {
                ans += r - l;
                l++, r--;
            }
        }
    }
    ans *= 2;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}