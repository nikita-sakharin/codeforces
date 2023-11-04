class Solution final {
public:
    constexpr int poorPigs(
        const int buckets,
        const int minutesToDie,
        const int minutesToTest
    ) const noexcept {
        const auto count{minutesToTest / minutesToDie};
        return max(1U, bit_width(static_cast<unsigned>(buckets) - 1));
    }
};
