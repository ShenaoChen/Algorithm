class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(m * n != original.size())
            return ans;
        ans.resize(m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i].push_back(original[n * i + j]);
            }
        }
        return ans;
    }
};
