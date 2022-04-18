#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int a[N];

bool check(int x, int n, int cnt){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= x) sum++;
        else if(a[i] == x - 1 && cnt > 0)
            sum++, cnt--;
    }
    return sum >= x;
}

int main() {
    int n, L;
    cin >> n >> L;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n, mid;
    while(l < r){
        mid = l + r + 1>> 1;
        if(check(mid, n, L))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}