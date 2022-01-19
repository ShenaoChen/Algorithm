class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> c;
        for(auto t : timePoints){
            int time = (t[3] - '0') * 10 + t[4] - '0';
            time += (t[0] - '0') * 600 + (t[1] - '0') * 60;
            c.push_back(time);
        }
        sort(c.begin(), c.end());
        int minTime = 60000;
        for(int i = 0; i < c.size() - 1; i++)
            minTime = min(minTime, c[i + 1] - c[i]);
        minTime = min(minTime, c[0] + 24 * 60 - c.back());
        return minTime;
    }
};
