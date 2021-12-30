class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> cnt;
        int n = hand.size();
        if(n % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        for(auto c : hand) cnt[c]++;
        for(auto c : hand){
            if(cnt[c] == 0)
                continue;
            for(int j = 0; j < groupSize; j++){
                if(cnt[c + j] == 0)
                    return false;
                cnt[c + j]--;
            }
        }
        return true;
    }
};
