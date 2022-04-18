#include<iostream>

using namespace std;

typedef long long ll;

int main(){
    int n;
    ll l, r, a;
    ll ans, tmp;
    cin>>n;
    while(n--){
        cin>>l>>r>>a;
        ans = r / a + r % a;
         if(r / a * a - 1 >= l)
            ans = max(ans, (r / a * a - 1) / a + (r / a * a - 1) % a);
        cout<< ans <<endl;
    }
    return 0;
}