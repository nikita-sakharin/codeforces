class Solution final {
public:
    inline int maxDistToClosest(const vector<int> &seats) const noexcept {
        const auto size{seats.size()};
        size_t maxDistance{0}, cnt{0};
        while (maxDistance < size && seats[maxDistance] == 0)
            ++maxDistance;
        for (size_t i{maxDistance}; i < size; ++i)
            if (seat == 0)
                ++cnt;
            else {
                maxDistance = max(maxDistance, (cnt + 1) >> 1);
                cnt = 0;
            }
        maxDistance = max(maxDistance, (cnt + 1) >> 1);
        return static_cast<int>(maxDistance);
    }
};
