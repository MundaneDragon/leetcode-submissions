class Solution {
private:
    const std::vector<std::string> phone_map = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const std::string& digits, int index, std::string& current, std::vector<std::string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        const std::string& letters = phone_map[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        auto result = std::vector<std::string>{};
        auto current = std::string{};

        backtrack(digits, 0, current, result);

        return result;
    }


};