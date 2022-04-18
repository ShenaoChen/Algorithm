#include <iostream>
#include <vector>

using namespace std;

vector<int> v, w;
int dp[200];

int main(){
    int n, C;
    v.push_back(0), w.push_back(0);
    cin>>n>>C;
    for(int i = 0; i < n; i++){
        int a, b, s;
        cin>>a>>b>>s;
        for(int k = 1; k <= s; k *= 2){
            v.push_back(a * k);
            w.push_back(b * k);
            s -= k;
        }
        if(s > 0){
            v.push_back(a * s);
            w.push_back(b * s);
        }
    }
    n = v.size() - 1;
    for(int i = 1; i <= n; i++)
        for(int j = C; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout<< dp[C] <<endl;
    return 0;
}