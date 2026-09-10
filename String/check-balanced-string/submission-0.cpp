class Solution {
public:
    bool isBalanced(string num) {
        auto sum_even = 0;
        auto sum_odd = 0;
        for (auto i = 0; i < num.size(); i++) {
            auto check = num[i] - '0';
            if (i % 2 == 0) {
                sum_even += check;
            } else {
                sum_odd += check;
            }
        }
        
        
        return sum_even == sum_odd;
    }
};