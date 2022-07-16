#include <iostream>

using namespace std;

const int N = 1e5 + 5;

bool st[N];

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    for (int i = 0; i <= d; i += k)
        st[i] = true;
    for (int i = 0; i <= d; i += l)
        st[i] = true;
    for (int i = 0; i <= d; i += m)
        st[i] = true;
    for (int i = 0; i <= d; i += n)
        st[i] = true;
    int ans = 0;
    for (int i = 1; i <= d; i++)    
        if (st[i]) ans++;
    cout << ans << endl;
    return 0;
}