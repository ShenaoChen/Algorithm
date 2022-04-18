#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;

int main() {
    vector<PII> segment;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; 
        cin >> a >> b;
        segment.push_back({a, b});
    }
    sort(segment.begin(), segment.end());
    priority_queue<int, vector<int>, greater<int>> heap;
    for(auto [l, r] : segment){
        if(heap.empty() || heap.top() >= l)
            heap.push(r);
        else{
            heap.pop();
            heap.push(r);
        }
    }
    cout << heap.size() << endl;
    return 0;
}