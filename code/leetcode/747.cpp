class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int pos = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[pos])
                pos = i;
            sum += nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[pos] < 2 * nums[i] && i != pos)
                return -1;
        return pos;
    }
};
