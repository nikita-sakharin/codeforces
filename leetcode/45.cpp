class Solution final {
public:
    constexpr int jump(const vector<int> &nums) noexcept {
        const auto last{nums.size() - 1};
        auto i{0UZ}, result{0UZ};

        while (i < last) {
            auto newI{0UZ}, maxJump{0UZ};
            const auto bound{last - i}, stop{min(size_t(nums[i]), bound)};
            for (auto j{1UZ}; j <= stop; ++j) {
                const auto jumpJ{i + j + min(bound - j, size_t(nums[i + j]))};
                if (jumpJ >= maxJump) {
                    newI = i + j;
                    maxJump = jumpJ;
                }
            }
            i = newI;
            ++result;
        }

        return int(result);
    }
};
