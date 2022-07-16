#include <iostream>

using namespace std;

int cnt[10];

int main() {
    int n, tmp, sum = 0, csum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cnt[tmp]++;
    }
    for (int i = 1; i <= 9; i++)
        sum = (sum + i * cnt[i]) % 3;
    if (sum == 1) {
        if (cnt[1] > 0) cnt[1]--;
        else if (cnt[4] > 0) cnt[4]--;
        else if (cnt[7] > 0) cnt[7]--;
        else if (cnt[2] > 1) cnt[2] -= 2;
        else if (cnt[2] > 0 && cnt[5] > 0) cnt[2]--, cnt[5]--;
        else if (cnt[5] > 1) cnt[5] -= 2;
        else if (cnt[2] > 0 && cnt[8] > 0) cnt[2]--, cnt[8]--;
        else if (cnt[5] > 0 && cnt[8] > 0) cnt[5]--, cnt[8]--;
        else if (cnt[8] > 1) cnt[8] -= 2;
    }
    else if (sum == 2) {
        if (cnt[2] > 0) cnt[2]--;
        else if (cnt[5] > 0) cnt[5]--;
        else if (cnt[8] > 0) cnt[8]--;
        else if (cnt[1] > 1) cnt[1] -= 2;
        else if (cnt[1] > 0 && cnt[4] > 0) cnt[1]--, cnt[4]--;
        else if (cnt[4] > 1) cnt[4] -= 2;
        else if (cnt[1] > 0 && cnt[7] > 0) cnt[1]--, cnt[7]--;
        else if (cnt[4] > 0 && cnt[7] > 0) cnt[4]--, cnt[7]--;
        else if (cnt[7] > 1) cnt[7] -= 2;
    }
    if (cnt[0] == 0)
        cout << -1 << endl;
    else {
        for (int i = 1; i <= 9; i++) csum += cnt[i];
        if (csum == 0) {
            cout << 0 << endl;
        }
        else {
            for (int i = 9; i >= 0; i--)
                for (int j = 0; j < cnt[i]; j++)
                    cout << i;
        }
    }
    return 0;
}