class Solution {
private:
    using dbl = double;

    static inline piecewise_linear_distribution<dbl> radiusDistribution(
        const dbl radius
    ) noexcept {
        const auto i = {0.0, radius}, w = {0.0, 2 / radius};
        return piecewise_linear_distribution(i.begin(), i.end(), w.begin());
    }

    default_random_engine eng{random_device{}()};
    const dbl radius{}, xCenter{}, yCenter{};
    piecewise_linear_distribution<dbl> rDist{radiusDistribution(radius)};
    uniform_real_distribution<dbl> phiDist{0.0, 2.0 * numbers::pi};

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
