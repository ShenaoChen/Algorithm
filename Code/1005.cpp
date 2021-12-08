class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int cnt[205] = {0};
        int ans = 0;
        for(auto num : nums){
            ans += num;
            cnt[num + 100]++;
        }
        for(int i = 0; i < 100; i ++){
            int t = min(k, cnt[i]);
            cnt[200 - i] += t;
            k -= t;
            ans += 2 * (100 - i) * t;
        }
        if(k & 1 == 1){
            for(int i = 100; i <= 200; i ++)
                if(cnt[i]){
                    ans -= 2 * (i - 100);
                    break;
                }
        }

        return ans;
    }
};
