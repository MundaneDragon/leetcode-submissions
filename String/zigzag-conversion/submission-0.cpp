class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        auto result = std::vector<string>(numRows);
        auto level = 0;
        auto direction = 1;
        for (auto character : s) {
            if (level + 1 >= numRows) {
                direction = -1;
            }

            if (level <= 0) {
                direction = 1;
            }

            result[level] += character;

            level += direction;
        }

        auto output = std::string{};
        for (auto level : result) {
            output.append(level);
        }
        
        return output;
    }
};