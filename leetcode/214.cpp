class Solution final {
private:
    template<class Iter, class Func>
    static constexpr void findPalindromes(
        const Iter first,
        const Iter last,
        const bool isOdd,
        Func func
    ) noexcept {
        using Difference = iterator_traits<Iter>::difference_type;

        if (first == last)
            return;
        const auto size{distance(first, last)};
        vector<Difference> buffer(size - !isOdd);
        for (Difference i{!isOdd}, left{0}, right{0}; i < size; ++i) {
            const auto bound{min(i + isOdd, size - i)};
            auto k{i >= right ? isOdd : min(buffer[left + (right - 1 - i)], right - i)};
            while (k < bound && first[i - !isOdd - k] == first[i + k])
                ++k;
            buffer[i - !isOdd] = k;
            if (i + k > right) {
                left = i + isOdd - k;
                right = i + k;
            }
            if (k != 0)
                func(first + i + isOdd - k, first + i + k);
        }
    }

public:
    constexpr string shortestPalindrome(const string &str) const noexcept {
        const auto strFirst{str.cbegin()}, strLast{str.cend()};
        string_view palindrome{};
        const auto func{
            [strFirst, &palindrome](
                const auto first,
                const auto last
            ) constexpr noexcept -> void {
                if (first == strFirst && size_t(distance(first, last)) > palindrome.size())
                    palindrome = string_view(first, last);
            }
        };

        findPalindromes(strFirst, strLast, false, func);
        findPalindromes(strFirst, strLast, true, func);

        const auto strSize{str.size()}, palindromeSize{palindrome.size()};
        string result{};
        result.reserve((strSize << 1) - palindromeSize);
        const auto iter{back_inserter(result)};
        copy(str.crbegin(), str.crbegin() + (strSize - palindromeSize), iter);
        copy(palindrome.cbegin(), palindrome.cend(), iter);
        copy(strFirst + palindromeSize, strLast, iter);

        return result;
    }
};
