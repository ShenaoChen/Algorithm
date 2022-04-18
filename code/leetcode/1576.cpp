class Solution {
public:
    string modifyString(string s) {
        int n = s.size(), k = 0, flag = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '?')
                continue;
            for(int j = 0; j < 26; j++){
                flag = 0;
                if(i - 1 >=0 && s[i - 1] == 'a' + j)
                    flag = 1;
                if(i + 1 < n && s[i + 1] == 'a' + j)
                    flag = 1;
                if(!flag){
                    s[i] = 'a' + j;
                     break;
                }
            }
        }
        return s;
    }
};
