class Solution final {
public:
    constexpr int poorPigs(
        const int buckets,
        [[maybe_unused]] const int minutesToDie,
        [[maybe_unused]] const int minutesToTest
    ) const noexcept {
        return max(1U, bit_width(static_cast<unsigned>(buckets) - 1));
    }
};
