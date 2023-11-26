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

        for (size_t i{0}; i < tSize; ++i)
            if (s[i] != t[i]) {
                return equal(
                    s.cbegin() + i + 1, s.cend(),
                    t.cbegin() + i + (sSize == tSize), t.cend()
                );
            }
        return sSize != tSize;
    }
};
