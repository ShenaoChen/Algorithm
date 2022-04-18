#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> PII;

map<PII, bool> m;
vector<PII> a;

int main() {
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back({x, y});
        m[{x, y}] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto [x1, y1] = a[i];
            auto [x2, y2] = a[j];
            if (m[{x1, y2}] || m[{x2, y1}])
                ans = max(ans, abs(x1 - x2) * abs(y1 - y2));
        }
    cout << ans << endl;
    return 0;
}