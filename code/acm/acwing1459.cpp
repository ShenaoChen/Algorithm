#include <iostream>

using namespace std;

const int N = 25;
int m[N][N];

int main() {
    int k, n;
    cin >> k >>n;
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++){
            int tmp;
            cin >> tmp;
            m[i][tmp] = j;
        }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool flag = true;
            for(int t = 1; t <= k; t++)
                if(m[t][i] <= m[t][j]){
                    flag = false;
                    break;
                }
            if(flag)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}