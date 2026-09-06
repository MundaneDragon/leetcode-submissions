class Solution {
public:
    vector<string> generateParenthesis(int n) {
        auto result = std::vector<std::string>{};
        auto temp = std::string{};
        backtrack(0, 0, n, result, temp);
        
        return result;
    }

    void backtrack(int openN, int closeN, int index, vector<string>& result, string& current) {
        if ((openN == index) && (closeN == index)) {
            result.push_back(current);
            return;
        }

        if (openN < index) {
            current.push_back('(');
            backtrack(openN+1, closeN, index, result, current);
            current.pop_back();
        }

        if (closeN < openN) {
            current.push_back(')');
            backtrack(openN, closeN+1, index, result, current);
            current.pop_back();
        }
    }
};