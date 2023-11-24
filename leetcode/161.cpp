class Solution final {
public:
    constexpr bool isOneEditDistance(
        const string &s,
        const string &t
    ) const noexcept {
        const auto sSize{s.size()}, tSize{t.size()};
        if (sSize < tSize)
            return isOneEditDistance(t, s);
        if (sSize - tSize > 1)
            return false;

        const auto notEqual{sSize != tSize};
        auto carry{false};
        for (size_t i{0}; i < tSize; ++i)
            if (s[i + (carry && notEqual)] != t[i]) {
                if (carry)
                    return false;
                carry = true;
            }
        return carry || notEqual;
    }
};
