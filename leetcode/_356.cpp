class Solution final {
private:
    struct Hash final {
    public:
        constexpr size_t operator()(const pair<int, int> &key) const noexcept {
            using llong = long long;

            static constexpr auto intWidth{numeric_limits<int>::digits + 1},
                llongWidth{numeric_limits<llong>::digits + 1},
                shift{min(intWidth, llongWidth - intWidth)};
            static constexpr hash<llong> hash{};

            return hash(llong{key.first} << shift ^ key.second);
        }
    };

public:
    inline bool isReflected(const vector<vector<int>> &points) const {
        auto minX{numeric_limits<int>::max()}, maxX{numeric_limits<int>::min()};
        unordered_set<pair<int, int>, Hash> pointSet;
        for (const auto &point : points) {
            const auto x{point[0]};
            minX = min(minX, x);
            maxX = max(maxX, x);
            pointSet.emplace(x, point[1]);
        }
        const auto doubleMiddle{minX + maxX};
        for (const auto &point : points)
            if (!pointSet.contains({doubleMiddle - point[0], point[1]}))
                return false;
        return true;
    }
};
