class Solution final {
public:
    constexpr int jump(const vector<int> &nums) noexcept {
        const auto last{nums.size() - 1};
        auto i{0UZ}, result{0UZ};

        while (i < last) {
            auto maxJump{0UZ};
            const auto bound{last - i}, stop{i + min(size_t(nums[i]), bound)};
            for (auto j{i + 1}; j <= stop; ++j) {
                const auto jumpJ{j + min(last - j, size_t(nums[j]))};
                if (jumpJ >= maxJump) {
                    i = j;
                    maxJump = jumpJ;
                }
            }
            ++result;
        }

        return int(result);
    }
};
