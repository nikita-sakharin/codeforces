class Solution final {
public:
    inline vector<int> sortedSquares(const vector<int> &nums) noexcept {
        const auto size{ssize(nums)};
        vector<int> result(size);
        ptrdiff_t i{0}, j{size - 1}, index{size};
        while (i <= j) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[--index] = nums[j] * nums[j];
                --j;
            } else {
                result[--index] = nums[i] * nums[i];
                ++i;
            }
        }
        return result;
    }
};
