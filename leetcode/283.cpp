class Solution final {
public:
    constexpr void moveZeroes(vector<int> &nums) const noexcept {
        const auto size{nums.size()};
        auto nonZero{0UZ};
        for (auto i{0UZ}; i < size; ++i)
            if (nums[i] != 0)
                swap(nums[nonZero++], nums[i]);
    }
};
