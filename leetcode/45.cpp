class Solution final {
public:
    constexpr int jump(const vector<int> &nums) noexcept {
        const auto last{nums.size() - 1};
        auto i{0UZ}, result{0UZ};

        while (i < last) {
            auto maxJump{0UZ};
            const auto stop{i + min(last - i, size_t(nums[i]))};
            for (auto j{i + 1}; j <= stop; ++j) {
                const auto jJump{j + min(last - j, size_t(nums[j]))};
                if (jJump >= maxJump) {
                    i = j;
                    maxJump = jJump;
                }
            }
            ++result;
        }
        return int(result);
    }
};
