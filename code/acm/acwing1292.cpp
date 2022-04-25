#include <iostream>

using namespace std;

const int N = 1e6 + 5;

int primes[N], cnt;
bool st[N];

void get_prime() {
    for (int i = 2; i < N; i++) {
        if (st[i]) continue;
        primes[cnt++] = i;
        for (int j = 0; primes[j] <= N / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    get_prime();
    while (scanf("%d", &n), n) {
        int l = 1, r = cnt - 1;
        while (l <= r) {
            int a = primes[l], b = primes[r];
            if (a + b == n) {
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
            if (a + b > n) r--;
            if (a + b < n) l++;
        }
    }
    return 0;
}