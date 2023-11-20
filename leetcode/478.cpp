class Solution {
private:
    using dbl = double;

    static constexpr auto i = {0, 1}, w = {0, 2};

    mt19937_64 eng{random_device{}()};
    piecewise_linear_distribution<dbl> rDist{i.begin(), i.end(), w.begin()};
    uniform_real_distribution<dbl> phiDist{0.0, 2.0 * numbers::pi};
    const dbl radius{}, xCenter{}, yCenter{};

    inline vector<dbl> toCircle(
        const dbl r,
        const dbl phi
    ) const noexcept {
        return {cos(phi) * r + xCenter, sin(phi) * r + yCenter};
    }

public:
    inline Solution(
        const dbl radius,
        const dbl xCenter,
        const dbl yCenter
    ) noexcept : radius{radius}, xCenter{xCenter}, yCenter{yCenter} {
    }

    inline vector<dbl> randPoint() noexcept {
        return toCircle(rDist(eng), phiDist(eng));
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
