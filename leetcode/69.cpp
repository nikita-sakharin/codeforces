class Solution final {
private:
    using uint = unsigned;

public:
    constexpr int mySqrt(const int x) const noexcept {
        if (x <= 1)
            return x;

        auto xCurrent{0}, xNext{1 << ((bit_width(uint(x) - 1) + 1) >> 1)};
        do {
            xCurrent = xNext;
            xNext = (xCurrent + x / xCurrent) >> 1;
        } while (xNext < xCurrent);

        return xCurrent;
    }
};
