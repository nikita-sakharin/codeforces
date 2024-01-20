class Solution final {
private:
    struct Hash final {
    private:
        using llong = long long;

        template<class T>
        static constexpr auto digits{numeric_limits<T>::digits};

        static constexpr auto
            shift{min(digits<int> + 1, digits<llong> - digits<int>)};
        static constexpr hash<llong> hashCode{};

    public:
        inline size_t operator()(const pair<int, int> &key) const noexcept {
            return hashCode(llong{key.first} << shift ^ key.second);
        }
    };

public:
    inline bool isReflected(const vector<vector<int>> &points) const noexcept {
        auto minX{numeric_limits<int>::max()}, maxX{numeric_limits<int>::min()};
        unordered_set<pair<int, int>, Hash> pointSet{};
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
