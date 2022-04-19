#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        vector<int> c;
        while (x) {
            c.push_back(x % 10);
            x /= 10;
        }
        int n = c.size();
        for (int i = 0; i < (n + 1) / 2; i++)
            if (c[i] != c[n - i - 1])
                return false;
        return true;
    }
};



