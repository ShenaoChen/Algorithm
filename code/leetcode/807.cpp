class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int ans = 0;
        int r[55] = {0};
        int c[55] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                r[i] = max(r[i], grid[i][j]);
                c[i] = max(c[i], grid[j][i]);
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans += max(0, min(r[i], c[j]) - grid[i][j]);
        return ans;
    }
};
