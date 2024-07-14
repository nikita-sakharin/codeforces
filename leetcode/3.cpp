class Solution final {
public:
    inline int lengthOfLongestSubstring(const string &s) const noexcept {
        const auto size{s.size()};
        auto result{0UZ};
        unordered_set<char> chars{};
        for (auto i{0UZ}; i < size; ++i) {
            const auto ch{s[i]};
            while (chars.contains(ch)) {
                const auto first{s[i - chars.size()]};
                chars.erase(first);
            }
            chars.insert(ch);
            result = max(result, chars.size());
        }
        return int(result);
    }
};
