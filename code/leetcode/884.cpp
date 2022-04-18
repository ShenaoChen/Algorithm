class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> hash;

        auto insert = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                hash[word]++;
            }
        };

        insert(s1);
        insert(s2);
        
        for(auto p : hash)
            if(p.second == 1)
                ans.push_back(p.first);
        return ans;
    }
};
