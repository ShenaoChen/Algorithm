class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        int end = 0;
        int n = s.size() + 1;
        for(int i = 1; i <= n; i++){
            if(i == n || s[i] == ' ')
                count++;
            if(count == k){
                end = i;
                break;
            }
        }
        return s.substr(0, end);
    }
};
