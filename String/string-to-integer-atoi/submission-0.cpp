#include <cmath>
#include <cctype>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        auto i = 0;
        auto n = s.length();
        
        while (i < n && s[i] == ' ') {
            i++;
        }

        auto sign = 1;
        if (i < n && s[i] == '+') {
            i++;
        } else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }

        long long total = 0;
        while (i < n && std::isdigit(s[i])) {
            total = total * 10 + (s[i] - '0');
            
            if (sign == 1 && total >= std::pow(2, 31) - 1) {
                return std::pow(2, 31) - 1;
            } else if (sign == -1 && -total <= -std::pow(2, 31)) {
                return -std::pow(2, 31);
            }
            i++;
        }
        
        return static_cast<int>(total * sign);
    }
};