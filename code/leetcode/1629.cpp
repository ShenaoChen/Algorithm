class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int lastTime = 0, maxTime = 0;
        char ch = 'a';
        int tmp;
        for(int i = 0; i < releaseTimes.size(); i++){
            tmp = releaseTimes[i] - lastTime;
            lastTime = releaseTimes[i];
            if(tmp > maxTime || tmp == maxTime && keysPressed[i] > ch){
                maxTime = tmp;
                ch = keysPressed[i];
            }
        }
        return ch;
    }
};
