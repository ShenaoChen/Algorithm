#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 5010;
int p[N], f[N], sum[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(f, 0, sizeof f);
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (p[j] < p[i])
                    f[i]++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++)
                if (p[j] > p[i]) f[j]--;
            sum[0] = 0;
            for (int j = 1; j <= i; j++) 
                sum[j] = sum[j - 1] + f[j];
            for (int j = 1; j < i; j++)
                if (p[j] < p[i]) ans += sum[i - 1] - sum[j];
        }
        cout << ans << endl;
    }
    return 0;
}