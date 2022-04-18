#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            m[nums[i]] = i;
        for (int i = 0; i < n; i++) {
            int tmp = target - nums[i];
            if (m.count(tmp) && m[tmp] != i) {
                ans.push_back(i);
                ans.push_back(m[tmp]);
                break;
            }
        }
        return ans;
    }
};
