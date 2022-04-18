#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
        ans += a[i] * (n - i - 1);
    cout << ans << endl;
    return 0;
}