#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

int primes[N], cnt;
int sum[N];
bool st[N];

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) 
                break;
        }
    }
}

int get(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> &A, int b) {
    int t = 0;
    vector<int> res;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    get_prime(N);
    for (int i = 0; i < cnt; i++)
        sum[i] = get(a, primes[i]) - get(b, primes[i]) - get(a - b, primes[i]);
    vector<int> ans;
    ans.push_back(1);
    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            ans = mul(ans, primes[i]);
    for (int i = ans.size() - 1; i >= 0; i--) 
        printf("%d", ans[i]);
    cout << endl;
    return 0;
}