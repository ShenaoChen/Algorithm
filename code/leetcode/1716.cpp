class Solution {
public:
    int totalMoney(int n) {
        int t = n / 7;
        if(t == 0)
            return n * (n + 1) / 2;
        int res = t * 28 +  t * (t - 1) / 2 * 7;
        int r = n % 7;
        res += r * (r + 1) / 2 + r * t;
        return res;
    }
};
