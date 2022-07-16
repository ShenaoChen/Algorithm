#include <iostream>

using namespace std;

int cnt[5];

int main() {
    int n, tmp, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cnt[tmp]++;
    }
    ans += cnt[4];
    cnt[1] = max(0, cnt[1] - cnt[3]);
    ans += cnt[3];
    ans += cnt[2] / 2;
    cnt[2] %= 2;
    if (cnt[2] == 1) {
        ans++;
        cnt[1] = max(0, cnt[1] - 2);
    }
    ans += cnt[1] / 4;
    ans += (cnt[1] % 4 ? 1 : 0);
    cout << ans << endl;
    return 0;
}