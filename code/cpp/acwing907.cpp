#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main() {
    vector<PII> segment;
    bool flag;
    int n, start, end, ans = 0;
    cin >> start >> end >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        segment.push_back({a, b});
    }
    sort(segment.begin(), segment.end());
    for(int i = 0; i < n; i++){
        int j = i, r = -2e9;
        while(j < n && segment[j].first <= start){
            r = max(r, segment[j].second);
            j++;
        }
        ans++;
        if(r < start)
            break;
        if(r >= end){
            flag = true;
            break;
        }
        start = r;
        i = j - 1;
    }
    if(!flag) ans = -1;
    cout << ans << endl;
    return 0;
}