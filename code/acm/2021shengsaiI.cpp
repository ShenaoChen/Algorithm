#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;

int a[maxn];
map<int, int> mp;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a, a + n);
	int sum = 0;
	if (mp[0] == 1)
		cout << "1" << endl;
	else if (mp[0] > 1)
		cout << 0 << endl;
	else {
		for(int i = 0; i < n; i++) {
			if (a[i] != 1)
				sum++;
			i += (mp[a[i]] - 1);
		}
        cout << sum << endl;
	}
}