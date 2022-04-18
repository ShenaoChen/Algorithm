#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main(){
    int n;
    cin >> n;
    vector<PII> a;
    for(int i = 0; i < n; i++){
        int w, s;
        cin >> w >> s;
        a.push_back({w, s});
    }
    sort(a.begin(), a.end(), [](PII a, PII b)->bool{return a.first + a.second < b.first + b.second;});
    int sum = 0, ans = -2e9;
    for(auto [w, s] : a){
        ans = max(ans, sum - s);
        sum += w;
    }
    cout << ans << endl;
    return 0;
}