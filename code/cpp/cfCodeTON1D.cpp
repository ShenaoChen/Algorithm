#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll x = n;
        while(x % 2 == 0) x /= 2;
        if(x == 1){
            cout << -1 << endl;
            continue;
        }
        if(x < 2e9 && x * (x + 1) / 2 <= n)
            cout << x << endl;
        else
            cout << n / x * 2 << endl;
    }
    return 0;
}