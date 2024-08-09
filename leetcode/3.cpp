class Solution final {
private:
    static constexpr auto printableChars{95UZ};

    static constexpr size_t order(const char ch) noexcept {
        return ch - ' ';
    }

public:
    inline int lengthOfLongestSubstring(const string &s) const noexcept {
        const auto size{s.size()};
        auto result{0UZ};
        bitset<printableChars> chars{};
        for (auto i{0UZ}; i < size; ++i) {
            const auto charOrder{order(s[i])};
            while (chars.test(charOrder))
                chars.reset(order(s[i - chars.count()]));
            chars.set(charOrder);
            result = max(result, chars.count());
        }
        return int(result);
    }
};
