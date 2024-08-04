class Solution final {
private:
    template<class Iter>
    using Difference = iterator_traits<Iter>::difference_type;

    template<class Iter, class Func, class Container = deque<Difference<Iter>>>
    static constexpr void findPalindromes(
        const Iter first,
        const Iter last,
        const bool isOdd,
        Func func
    ) noexcept {
        const auto size{distance(first, last)};
        Container buffer{};
        for (Difference<Iter> i{!isOdd}, left{0}, right{-1}; i < size; ++i) {
            auto k{i > right ? isOdd : min(buffer[left + (right - i)], right + 1 - i)};
            while (k < min(i + isOdd, size - i) && first[i - !isOdd - k] == first[i + k])
                ++k;
            buffer.push_back(k);
            if (i - 1 + k > right) {
                left = i + isOdd - k;
                right = i - 1 + k;
            }
            func(first + i + isOdd - k, first + i + k);
        }
    }

public:
    constexpr string longestPalindrome(const string &s) const noexcept {
        string_view result{};
        const auto func{
            [&result](
                const auto first,
                const auto last
            ) constexpr noexcept -> void {
                if (size_t(distance(first, last)) > result.size())
                    result = string_view(first, last);
            }
        };
        findPalindromes(s.cbegin(), s.cend(), false, func);
        findPalindromes(s.cbegin(), s.cend(), true, func);
        return string(result);
    }
};
