#include<iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int a[N];

int main(){
    int n;
    ll m, p1, s1, s2;
    cin>>n;
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
    }
    cin>>m>>p1>>s1>>s2;
    ll sum1 = 0, sum2 =  0;
    for(int i = 1; i < m; i++)
        sum1 += 1ll * a[i] * (m - i);
    for(int i = m + 1; i <= n; i++)
        sum2 += 1ll * a[i] * (i - m);
    ll tmp = 1ll * abs(m - p1) * s1;
    if(p1 < m) sum1 += tmp;
    if(p1 > m) sum2 += tmp;
    int ans = m;
    tmp = abs(sum1 - sum2);
    for(int i = 1; i < m; i++){
        if(abs(sum1 + 1ll * s2 * (m - i) - sum2) < tmp){
            ans = i;
            tmp = abs(sum1 + 1ll * s2 * (m - i) - sum2);
        }
    }
    for(int i = m + 1; i <= n; i++){
        if(abs(sum2 + 1ll * s2 * (i - m) - sum1) < tmp){
            ans = i;
            tmp = abs(sum2 + 1ll * s2 * (i - m) - sum1);
        }
    }
    cout<< ans <<endl;
}