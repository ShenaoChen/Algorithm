#include<iostream>

using namespace std;

typedef long long ll;

ll getPre(ll x){
    int cnt = 0;
    int v[20] = {0};
    while(x){
        v[cnt++] = x % 10;
        x /= 10;
    }
    for(int i = cnt - 1; i >= 0; i--){
        if(v[i] & 1){
            v[i]--;
            for(int j = i - 1; j >= 0; j--)
                v[j] = 8;
            break;
        }
    }
    ll ans = 0;
    while(cnt >= 0){
        ans = ans * 10 + v[cnt--];
    }
    return ans;
}

ll getNext(ll x){
    int cnt = 0;
    int v[20] = {0};
    while(x){
        v[cnt++] = x % 10;
        x /= 10;
    }
    for(int i = cnt - 1; i >= 0; i--){
        if(v[i] & 1){
            if (v[i] == 9) {
                int j = i + 1;
                while(v[j] == 8) j++;
                v[j] += 2;
                while(--j >= 0) v[j] == 0;
            } else {
              v[i]++;
              for (int j = i - 1; j >= 0; j--)
                v[j] = 0;
            }
            break;
        }
    }
    ll ans = 0;
    while(cnt >= 0){
        ans = ans * 10 + v[cnt--];
    }
    return ans;
}

int main(){
    int t;
    ll n;
    cin>>t;
    for (int i = 1; i <= t; i++) {
      cin>>n;
      ll l = getPre(n);
      ll r = getNext(n);
      cout<<"Case #"<<i<<": "<<min(n - l, r - n)<<endl;
    }
    return 0;
}