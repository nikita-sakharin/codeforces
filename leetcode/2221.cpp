class Solution {
private:
    static constexpr size_t maxLength{1000};
    static constexpr int mod{10};

    template<typename ForwardIter>
    static constexpr void pascalTriangleRow(
        ForwardIter first,
        const size_t rowIndex
    ) noexcept {
        auto prev = *first++ = 1;
        for (size_t k{0}; k < rowIndex; ++k)
            *first++ = prev = prev * (rowIndex - k) / (k + 1);
    }

public:
    constexpr int triangularSum(const vector<int> &nums) const noexcept {
        const auto size{nums.size()};
        array<int, maxLength> row;
        pascalTriangleRow(row.begin(), size - 1);
        auto result{0};
        for (size_t i{0}; i < size; ++i) {
            result += nums[i] * (row[i] % 10);
            result %= 10;
        }
        return result;
    }
};
