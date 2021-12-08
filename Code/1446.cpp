class Solution {
public:
    int maxPower(string s) {
        int ans = 1, tmp = 1;
        char c = s[0];
        for(int i = 1; i < s.size(); i ++){
            if(s[i] != c){
                ans = max(ans, tmp);
                tmp = 1;
                c = s[i];
            }
            else
                tmp ++;
        }
        ans = max(ans, tmp);
        return ans;
    }
};
