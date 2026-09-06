class Solution {
public:
    string addBinary(string a, string b) {
        auto result = std::string{};

        auto i = static_cast<int>(a.size()) - 1;
        auto j = static_cast<int>(b.size()) - 1;
        auto carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            auto sum = carry;

            if (i >= 0) {
                sum += (a[i--] == '1' ? 1 : 0);
            }
            if (j >= 0) {
                sum += (b[j--] == '1' ? 1 : 0);
            }

            result.push_back((sum % 2 == 1) ? '1' : '0');
            carry = sum / 2;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};