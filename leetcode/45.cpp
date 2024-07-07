class Solution final {
public:
    constexpr int jump(const vector<int> &nums) noexcept {
        const auto last{nums.size() - 1};
        auto i{0UZ}, maxJump{0UZ}, result{0UZ};

        while (maxJump < last) {
            const auto stop{maxJump};
            for (maxJump = 0; i <= stop; ++i)
                maxJump = max(maxJump, i + min(last - i, size_t(nums[i])));
            ++result;
        }
        return int(result);
    }
};
