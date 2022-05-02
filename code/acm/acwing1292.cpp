#include <iostream>

using namespace std;

const int N = 1e6 + 5;

int primes[N], cnt;
bool st[N];

void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    get_prime(1e6);
    while (scanf("%d", &n), n) {
        for (int i = 1; i < cnt ; i++) {
            int a = primes[i];
            int b = n - a;
            if (!st[b]) {
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
        }
    }
    return 0;
}