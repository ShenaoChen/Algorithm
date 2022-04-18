#include <iostream>

using namespace std;

bool check(int x){
    if(x % 9 == 0)
        return false;
    int tmp;
    while(x){
        tmp = x % 10;
        if(tmp == 9)
            return false;
        x /= 10;
    }
    return true;
}

void solve(int f, int l, int i){
    int ans = 0;
    for(int j = f; j <= l; j++)
        if(check(j)) ans++;
    printf("Case #%d: %d\n",i, ans);
}

int main(){
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        int f, l;
        cin>>f>>l;
        solve(f, l, i);
    }
    return 0;
}