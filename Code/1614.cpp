class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, tmp = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                tmp++;
            if(s[i] == ')')
                tmp--;
            ans = max(ans, tmp);
        }
        return ans;
    }
};
