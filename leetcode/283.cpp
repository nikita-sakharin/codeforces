class Solution final {
public:
    constexpr void moveZeroes(vector<int> &nums) const noexcept {
        const auto size{nums.size()};
        size_t nonZero{0};
        for (size_t i{0}; i < size; ++i)
            if (nums[i] != 0)
                swap(nums[nonZero++], nums[i]);
    }
};
