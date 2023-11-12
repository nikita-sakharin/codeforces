class Solution final {
private:
    struct Hash final {
    private:
        using uint = unsigned;
        using llong = long long;

        static constexpr hash<llong> hash{};

    public:
        inline size_t operator()(const pair<int, int> &key) const noexcept {
            const auto high{static_cast<llong>(key.first)},
                low{static_cast<llong>(key.second)};
            return hash((high << numeric_limits<uint>::digits) + low);
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
