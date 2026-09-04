class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }

        auto prev_1 = 2;
        auto prev_2 = 1;
        auto result = 0;
        for (auto i = 3; i <= n; i++) {
            result = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = result;

        }
        
        return result;
    }
};