#include <iostream>
#include <vector>

using namespace std;

int p[40] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

int main() {
    int k;
    int cnt;
    vector<int> ans;
    int t = 0;
    cin >> k;
    if (k == 0) {
        cout << 8 << endl;
        cout << "1 2 3 4 3 2 1 2" << endl;
        return 0;
    }
    if (k == 1) {
        cout << 6 << endl;
        cout << "1 1 4 5 1 4" <<endl;
        return 0;
    }
    if (k == 2) {
        cout << 1 << endl;
        cout << 1 <<endl;
        return 0;
    }
    while (k > 1) {
        t++;
        for (int i = 0; i < 40; i++) {
            if (p[i] > k){
                cnt = i - 1;
                break;
            }
        }
        k = k - p[cnt] + 1;
        for (int i = 0; i < cnt; i++) 
            ans.push_back(t);
    }
    if (ans.size() > 365)
        cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        for (auto c : ans)
            cout << c << ' ';
    }
    return 0;
}