class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> tmp, ans;
        int s = 0, e = 0;
        for(int i = 0; i < text.size(); i++){
            e = i;
            if(text[i] == ' '){
                tmp.push_back(text.substr(s,e - s));
                s = i + 1;
            }
        }
        tmp.push_back(text.substr(s, e - s + 1));
        for(int i = 0; i < tmp.size() - 2; i++)
            if(tmp[i] == first && tmp[i + 1] == second)
                ans.push_back(tmp[i + 2]);
        return ans;
    }
};
