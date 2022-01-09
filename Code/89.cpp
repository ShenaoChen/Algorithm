class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int size = 1<<n;
        for(int i = 0; i < size; i++)
            ans.push_back(i>>1^i);
        return ans;
    }
};
