class Solution final {
private:
    template<class T>
    static constexpr auto digits10{numeric_limits<T>::digits10};

public:
    constexpr bool isPalindrome(const int x) const noexcept {
        if (x < 0)
            return false;

        array<char, digits10<decltype(x)> + 1> str{};
        const auto
            size{size_t(to_chars(str.begin(), str.end(), x).ptr - str.begin())},
            lastIndex{size - 1}, half{size >> 1};
        for (auto i{0UZ}; i < half; ++i)
            if (str[i] != str[lastIndex - i])
                return false;
        return true;
    }
};
