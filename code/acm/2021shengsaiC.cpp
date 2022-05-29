#include<iostream>

using namespace std;

typedef long long ll;

ll l,r,k;

bool check(ll x) {
    if (r / x * x - (k - 1) * x >= l) 
        return true;
    else return false;
}

int main() {
    cin >> l >> r >> k;
    ll a = 1, b = (r - l + 1) / (k - 1);
    ll mid;
    while (a < b) {
        mid = (a + b + 1) >> 1;
        if (check(mid)) a = mid;
        else b = mid - 1;
    }
    if (a < l) {
        while (l * k <= r) {
            a++;
            l++;
        }
    }
    cout << a << endl;
}