class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int length = nums.size();
        int r = 0;
        if(length < 2)
            return false;
        unordered_map<int,int> hash;
        hash[0] = -1;
        for(int i = 0; i < length; i++){
            r = (r + nums[i]) % k;
            if(hash.count(r)){
                int prevIndex = hash[r];
                if(i - prevIndex >= 2)
                    return true;
            }
            else
                hash[r] = i;
        }
        return false;
    }
};
