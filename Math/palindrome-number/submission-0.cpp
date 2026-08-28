#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x == 0) {
            return true;
        }

        if (x % 10 == 0) {
            return false;
        }

        auto reverse_num = static_cast<long>(0);
        auto original = x;
        while (original > 0) {
            auto quotient = original / 10;
            auto remainder = original % 10;
            reverse_num = (reverse_num * 10) + remainder;
            original = quotient;
        }
        
        return reverse_num == x;
    }
};