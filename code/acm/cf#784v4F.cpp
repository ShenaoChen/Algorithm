#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> PII;

const int N = 2e5 + 5;

int a[N];

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    vector<PII> x, y;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    left[0] = 0, right[0] = 0;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += a[i];
        left[sum1] = i + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        sum2 += a[i];
        right[sum2] = n - i;
    }
    for (auto item : left) x.push_back(item);
    for (auto item : right) y.push_back(item);
    sort(x.begin(), x.end(), greater<PII>());
    sort(y.begin(), y.end(), greater<PII>());
    for (int i = 0, j = 0; i < x.size() && j < y.size();) {
        if (x[i].first == y[j].first )  {
            if (x[i].second + y[j].second <= n) {
                cout << x[i].second + y[j].second << endl;
                return;
            }
            i++, j++;
        }
        if (x[i].first < y[j].first) j++;
        if (x[i].first > y[j].first) i++;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}