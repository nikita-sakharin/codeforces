class Solution final {
public:
    constexpr bool canJump(const vector<int> &nums) noexcept {
        const auto size{nums.size()};
        for (auto i{0UZ}, maxI{0UZ}; i < size; ++i) {
            if (i > maxI)
                return false;
            maxI = max(maxI, i + min(size - i, size_t(nums[i])));
        }
        return true;
    }
};
