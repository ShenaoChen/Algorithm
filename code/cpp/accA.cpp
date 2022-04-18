#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

unordered_map<int, int> m;

void solve(int x){
    ll ans = x == 0 ? 1 : 0;
    while(x){
        int tmp = x % 16;
        x /= 16;
        ans += m[tmp];
    }
    cout << ans <<endl;
}

int main(){
    m[0] = m[4] = m[6] = m[9] = m[10] = m[13] = 1;
    m[8] = m[11] = 2;
    int n;
    cin>>n;
    solve(n);
    return 0;
}