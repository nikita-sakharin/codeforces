class Solution final {
public:
    constexpr int jump(const vector<int> &nums) noexcept {
        const auto last{nums.size() - 1};
        auto i{0UZ}, nextI{0UZ}, result{0UZ};

        while (nextI < last) {
            const auto stop{nextI};
            for (nextI = 0; i <= stop; ++i)
                nextI = max(nextI, i + min(last - i, size_t(nums[i])));
            ++result;
        }
        return int(result);
    }
};
