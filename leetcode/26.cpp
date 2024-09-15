class Solution final {
public:
    constexpr int removeDuplicates(vector<int> &nums) const noexcept {
        const auto length{nums.size()};
        auto newSize{1UZ};
        for (auto i{1UZ}; i < length; ++i)
            if (nums[i - 1] != nums[i])
                nums[newSize++] = nums[i];
        nums.resize(newSize);
        return int(newSize);
    }
};
