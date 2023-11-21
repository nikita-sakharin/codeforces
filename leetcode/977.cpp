class Solution {
public:
    inline vector<int> sortedSquares(const vector<int> &nums) noexcept {
        const auto size{ssize(nums)};
        vector<int> result;
        result.reserve(size);
        auto j{lower_bound(nums.cbegin(), nums.cend(), 0) - nums.cbegin()},
            i{j - 1};
        while (i >= 0 || j < size) {
            if (i < 0 || (j < size && nums[i] * nums[i] > nums[j] * nums[j])) {
                result.push_back(nums[j] * nums[j]);
                ++j;
            } else {
                result.push_back(nums[i] * nums[i]);
                --i;
            }
        }
        return result;
    }
};
