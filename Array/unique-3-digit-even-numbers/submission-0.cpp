#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        // Count frequency of each digit available in the input
        std::vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int distinctEvenCount = 0;

        // Check all 3-digit even numbers: 100, 102, ..., 998
        for (int num = 100; num < 1000; num += 2) {
            int d1 = num / 100;        // Hundreds place
            int d2 = (num / 10) % 10;  // Tens place
            int d3 = num % 10;         // Units place

            // Count occurrences of digits needed for 'num'
            std::vector<int> needed(10, 0);
            needed[d1]++;
            needed[d2]++;
            needed[d3]++;

            // Verify if we have enough of each digit
            if (needed[d1] <= count[d1] &&
                needed[d2] <= count[d2] &&
                needed[d3] <= count[d3]) {
                distinctEvenCount++;
            }
        }

        return distinctEvenCount;
    }
};