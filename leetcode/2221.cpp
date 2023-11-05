class Solution final {
private:
    static constexpr size_t maxLength{1000};
    static constexpr int mod{10};
    static constexpr array<int, mod> mod10Inverse{0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
    static constexpr array<int, 4> remainders{6, 2, 4, 8};

    template<typename ForwardIter>
    static constexpr void pascalTriangleRow(
        ForwardIter first,
        const size_t rowIndex
    ) noexcept {
        auto binomial = *first++ = 1;
        for (size_t k{0}, exp2{0}, exp5{0}; k < rowIndex; ++first, ++k) {
            auto multiplier{rowIndex - k}, divider{k + 1};

            while (multiplier % 5 == 0) {
                ++exp5;
                multiplier /= 5;
            }
            const auto multiplierTwos{countr_zero(multiplier)};
            exp2 += multiplierTwos;
            multiplier >>= multiplierTwos;
            binomial = binomial * divider % mod;

            while (divider % 5 == 0) {
                --exp5;
                divider /= 5;
            }
            const auto dividerTwos{countr_zero(divider)};
            exp2 -= dividerTwos;
            divider >>= dividerTwos;
            binomial = binomial * mod10Inverse[divider % mod] % mod;

            if (!exp2 && !exp5)
                *first = binomial;
            else if (exp2 && !exp5)
                *first = binomial * remainders[exp2 & 0X3] % mod;
            else if (exp2 && !exp5)
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
        for (size_t i{0}; i < size; ++i)
            result = (result + nums[i] * row[i]) % mod;
        return result;
    }
};
