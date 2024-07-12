class Solution final {
public:
    constexpr int removeElement(
        vector<int> &nums,
        const int val
    ) const noexcept {
        const auto size{nums.size()};
        auto newSize{0UZ};
        for (auto i{0UZ}; i < size; ++i)
            if (nums[i] != val)
                nums[newSize++] = nums[i];
        nums.resize(newSize);
        return int(newSize);
    }
};
