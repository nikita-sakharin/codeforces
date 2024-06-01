class Solution final {
private:
    template<class Iter>
    static constexpr void merge(
        Iter first,
        const Iter middle,
        const Iter last
    ) noexcept {
        using Value = iterator_traits<Iter>::value_type;

        if (middle == last)
            return;
        queue<Value> buffer{};
        auto second{middle};
        auto leftNonEmpty{first != middle};
        do {
            if (leftNonEmpty)
                buffer.push(move(*first));
            if (buffer.empty() || (second != last && *second < buffer.front())) {
                *first = move(*second);
                ++second;
            } else {
                *first = move(buffer.front());
                buffer.pop();
            }
            ++first;
            leftNonEmpty = leftNonEmpty && first != middle;
        } while (leftNonEmpty || !buffer.empty());
    }

    template<class Iter>
    static constexpr void mergeSort(
        const Iter first,
        const Iter last
    ) noexcept {
        using Difference = iterator_traits<Iter>::difference_type;

        const auto size{distance(first, last)}, half{size >> 1};
        Difference width{1};
        while (width < size) {
            auto n{size};
            auto iter{first};
            while (n != 0) {
                const auto left{min(width, n)}, right{min(width, n - left)};
                const auto middle{next(iter, left)},
                    nextIter{next(middle, right)};
                merge(iter, middle, nextIter);
                n -= left + right;
                iter = nextIter;
            }
            width = width <= half ? width << 1 : size;
        }
    }

public:
    inline vector<int> sortArray(vector<int> &nums) const noexcept {
        mergeSort(nums.begin(), nums.end());
        return move(nums);
    }
};
