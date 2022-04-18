#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin>>t;
	while(t--){
		ll n, a, b;
		cin >> n >> a >> b;
        cout << 1 + (n - 1) * a / b << endl;
	}
}