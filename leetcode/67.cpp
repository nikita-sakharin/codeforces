class Solution final {
public:
    inline string addBinary(const string &a, const string &b) const noexcept {
        const auto aSize{a.size()}, bSize{b.size()};
        if (aSize < bSize)
            return addBinary(b, a);
        string result(aSize, '\0');
        auto carry{false};
        for (size_t i{0}; i < aSize; ++i) {
            const auto
                left{a[aSize - i - 1] - '0'},
                right{i < bSize ? b[bSize - i - 1] - '0' : 0},
                sum{carry + left + right};
            result[aSize - i - 1] = '0' + (sum & 1);
            carry = sum >> 1;
        }
        if (carry)
            result.insert(result.cbegin(), '1');
        return move(result);
    }
};
