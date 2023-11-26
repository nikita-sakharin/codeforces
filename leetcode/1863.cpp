class Solution final {
public:
    constexpr int subsetXORSum(const vector<int> &nums) const noexcept {
        const auto count{1 << (nums.size() - 1)};
        return accumulate(nums.cbegin(), nums.cend(), 0, bit_or{}) * count;
    }
};
