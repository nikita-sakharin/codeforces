class Solution final {
public:
    constexpr void reverseString(vector<char> &s) const noexcept {
        for (auto i{0UZ}, j{s.size() - 1}; i < j; ++i, --j)
            swap(s[i], s[j]);
    }
};
