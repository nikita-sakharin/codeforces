class Solution final {
public:
    constexpr int removeElement(
        vector<int> &nums,
        const int val
    ) const noexcept {
        const auto size{nums.size()};
        size_t newSize{0};
        for (size_t i{0}; i < size; ++i)
            if (nums[i] != val)
                nums[newSize++] = nums[i];
        nums.resize(newSize);
        return int(newSize);
    }
};
