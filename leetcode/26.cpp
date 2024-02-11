class Solution final {
public:
    constexpr int removeDuplicates(vector<int> &nums) const noexcept {
        const auto size{nums.size()};
        size_t newSize{1};
        for (size_t i{1}; i < size; ++i)
            if (nums[i - 1] != nums[i])
                nums[newSize++] = nums[i];
        nums.resize(newSize);
        return newSize;
    }
};
