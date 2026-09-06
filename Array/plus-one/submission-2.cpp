class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it < 9) {
                ++(*it);
                return digits;
            }
            *it = 0;
        }

        // If all digits were 9 (e.g., [9,9,9] -> [0,0,0]):
        // Set first element to 1 and append 0 -> [1,0,0,0]
        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};