class Solution final {
public:
    constexpr int searchInsert(
        const vector<int> &nums,
        const int target
    ) const noexcept {
        const auto size{nums.size()};
        for (auto i{0UZ}; i < size; ++i)
            if (nums[i] >= target)
                return int(i);
        return size;
    }
};
