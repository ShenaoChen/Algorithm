class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        string medal[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> arr;
        vector<string> answer(n);

        for(int i = 0; i < n; i ++)
            arr.push_back({-score[i], i});

        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; i ++){
            if(i < 3)
                answer[arr[i].second] = medal[i];
            else
                answer[arr[i].second] = to_string(i + 1);
        }

        return answer;
    }
};
