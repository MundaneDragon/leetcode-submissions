class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
       auto size = static_cast<int>(digits.size());
       auto visited = std::vector<bool>(1000, false);
       auto result = 0;
       for (auto i = 0; i < size; i++) {
            if (digits[i] == 0) {
                continue;
            }
            for (auto j = 0; j < size; j++) {
                if (i == j) {
                    continue;
                }
                for (auto k =0; k < size; k++) {
                    if (i == k || j == k || digits[k] % 2 != 0) {
                        continue;
                    }

                    auto index = digits[i] * 100 + digits[j] * 10 + digits[k] * 1;
                    if (!visited[index]) {
                        result++;
                        visited[index] = true;
                    }
                }
            }
       }

       return result;
    }
};