class Solution final {
public:
    inline vector<int> plusOne(vector<int> &digits) const noexcept {
        auto carry{false};
        for (ptrdiff_t i(digits.size() - 1); i >= 0; --i) {
            if (++digits[i] < 10) {
                carry = false;
                break;
            }
            carry = true;
            digits[i] = 0;
        }
        if (carry)
            digits.insert(digits.cbegin(), 1);
        return digits;
    }
};
