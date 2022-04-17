#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int tmp = a[0], ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - tmp >= k) {
            ans++;
            tmp = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}