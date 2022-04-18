#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int a[N];

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int mid = n / 2;
    for(int i = 0; i < n; i++)
        ans += abs(a[i] - a[mid]);
    cout << ans << endl;
    return 0;
}