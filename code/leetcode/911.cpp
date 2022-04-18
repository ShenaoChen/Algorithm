class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int top = -1;
        voteCounts[-1] = -1;
        for(auto p : persons){
            voteCounts[p] ++;
            if(voteCounts[p] >= voteCounts[top])
                top = p;
            tops.push_back(top);
        }
        this->times = times;
    }
    
    int q(int t) {
        int pos = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return tops[pos];
    }
private:
   vector<int> tops;
   vector<int> times;
   unordered_map<int, int> voteCounts;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
