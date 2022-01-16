class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> tmp;
        for(auto ch : s){
            if(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z')
                tmp.push_back(ch);
            if(ch >= 'A' && ch <= 'Z')
                tmp.push_back('a' + ch - 'A');
        }
        int i = 0, j = tmp.size() - 1 ;
        while(i < j){
            if(tmp[i++] != tmp[j--])
                return false;
        }
        return true;
    }
};
