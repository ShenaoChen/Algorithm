class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto item : left)
            ans = max(ans, item);
        for(auto item : right)
            ans = max(ans, n - item);
        return ans;
    }
};
