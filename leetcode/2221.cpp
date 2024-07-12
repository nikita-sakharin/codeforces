class Solution final {
private:
    using uint = unsigned;

    static constexpr size_t maxLength{1000};
    static constexpr auto mod{10};
    static constexpr array<int, mod> mod10Inverse{0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
    static constexpr array<int, 4> remainders{6, 2, 4, 8};

    template<class T>
    static constexpr pair<T, uint> factorize(
        T value,
        const T divider
    ) noexcept {
        auto result{0U};
        while (value % divider == T{0}) {
            value /= divider;
            ++result;
        };
        return {value, result};
    }

    template<class ForwardIter>
    static constexpr void pascalTriangleRow(
        ForwardIter first,
        const size_t rowIndex
    ) noexcept {
        auto binomial = *first++ = 1;
        for (auto k{0UZ}, exp2{0UZ}, exp5{0UZ}; k < rowIndex; ++first, ++k) {
            auto multiplier{rowIndex - k}, divider{k + 1};
            auto diff{0U};

            const auto multiplierTwos{countr_zero(multiplier)};
            exp2 += multiplierTwos;
            multiplier >>= multiplierTwos;
            tie(multiplier, diff) = factorize(multiplier, size_t{5});
            exp5 += diff;
            binomial = binomial * multiplier % mod;

            const auto dividerTwos{countr_zero(divider)};
            exp2 -= dividerTwos;
            divider >>= dividerTwos;
            tie(divider, diff) = factorize(divider, size_t{5});
            exp5 -= diff;
            binomial = binomial * mod10Inverse[divider % mod] % mod;

            if (!exp2 && !exp5)
                *first = binomial;
            else if (exp2 && !exp5)
                *first = binomial * remainders[exp2 & 0X3] % mod;
            else if (!exp2 && exp5)
                *first = binomial * 5 % mod;
            else
                *first = 0;
        }
    }

public:
    constexpr int triangularSum(const vector<int> &nums) const noexcept {
        const auto size{nums.size()};
        array<int, maxLength> row;
        pascalTriangleRow(row.begin(), size - 1);
        auto result{0};
        for (auto i{0UZ}; i < size; ++i)
            result = (result + nums[i] * row[i]) % mod;
        return result;
    }
};
