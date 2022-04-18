class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int cnt = 0, ans = 0;
        vector<int> a(n + 1), b(n + 1);
        for(auto p : trust){
            a[p[0]]++;
            b[p[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(cnt == 2)
                return -1;
            if(a[i] == 0 && b[i] == n - 1){
                ans = i;
                cnt++;
            }
        }
        return cnt == 1 ? ans : -1;
    }
};
