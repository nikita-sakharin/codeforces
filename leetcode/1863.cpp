class Solution final {
public:
    constexpr int subsetXORSum(const vector<int> &nums) const noexcept {
        const size_t bound{1U << nums.size()};
        auto result{0};
        for (size_t i{0}; i < bound; ++i)
            result += totalXOR(nums, i);
        return result;
    }

    constexpr int totalXOR(
        const vector<int> &nums,
        const size_t mask
    ) const noexcept {
        const size_t size{nums.size()};
        const bitset<numeric_limits<size_t>::digits> bits{mask};
        auto result{0};
        for (size_t i{0}; i < size; ++i)
            if (bits[i])
                result ^= nums[i];
        return result;
    }
};
