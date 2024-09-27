class Solution final {
private:
    template<class T>
    static constexpr auto digits10{numeric_limits<T>::digits10};

public:
    constexpr bool isPalindrome(const int x) const noexcept {
        if (x < 0)
            return false;

        array<char, digits10<decltype(x)> + 1> str{};
        auto first{data(str)}, last{to_chars(begin(str), end(str), x).ptr - 1};
        while (first < last) {
            if (*first != *last)
                return false;
            ++first;
            --last;
        }

        return true;
    }
};
