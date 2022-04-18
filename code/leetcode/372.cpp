class Solution {
public:
    typedef long long ll;
    const int mod = 1337;

    ll pow(ll a, ll b){
        ll c = 1;
        while(b){
            if(b & 1)
                c = c * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return c;
    }
    
    int superPow(int a, vector<int>& b) {
        ll c = 1;
        for(int i = b.size() - 1; i >= 0; i --){
            c = c * pow(a, b[i]) % mod;
            a = pow(a, 10);
        }
        return c;
    }
};
