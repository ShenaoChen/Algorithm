#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

int main() {
    vector<PII> segments;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b; 
        segments.push_back({a, b});
    }
    sort(segments.begin(), segments.end(), [](PII A, PII B)->bool{return A.second < B.second;});
    int ans = 0, pos = -2e9;
    for(auto [l, r] : segments){
        if(l <= pos) continue;
        ans++;
        pos = r;
    }
    cout << ans << endl;
    return 0;
}