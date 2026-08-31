
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        auto result = 0;
        while(x) {
            if (result > ((pow(2,31)) - 1)/10 ||  result < (-pow(2,31))/10) {
                return 0;
            }

            result = result*10 + x%10;
            x = x/10;    
        }

        return result;
    }
};