class Solution final {
public:
    inline string longestPalindrome(const string &s) const noexcept {
        const auto size{s.size()};
        string_view result{};
        vector<size_t> even(size), odd(size);
        for (ptrdiff_t i{0}, left{0}, right{-1}; i < size; ++i) {
            auto k{i > right ? 0 : min(ptrdiff_t(even[left + (right + 1 - i)]), right + 1 - i)};
            while (k < i && i + k < size && s[size_t(i - 1 - k)] == s[size_t(i + k)])
                ++k;
            even[i] = k;
            if (i - 1 + k > right) {
                left = i - k;
                right = i - 1 + k;
            }
            if (const size_t newSize(k << 1); newSize > result.size())
                result = string_view(s.data() + i - k, newSize);
        }
        for (ptrdiff_t i{0}, left{0}, right{-1}; i < size; ++i) {
            auto k{i > right ? 1 : min(ptrdiff_t(odd[left + (right - i)]), right + 1 - i)};
            while (k <= i && i + k < size && s[size_t(i - k)] == s[size_t(i + k)])
                ++k;
            odd[i] = k;
            if (i - 1 + k > right) {
                left = i + 1 - k;
                right = i - 1 + k;
            }
            if (const size_t newSize((k << 1) - 1); newSize > result.size())
                result = string_view(s.data() + i + 1 - k, newSize);
        }
        return string(result);
    }
};
