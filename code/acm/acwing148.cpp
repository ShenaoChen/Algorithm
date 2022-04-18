#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> heap;
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push(x);
    }
    while(heap.size() > 1){
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        ans += a + b;
        heap.push(a + b);
    }
    cout << ans << endl;
    return 0;
}