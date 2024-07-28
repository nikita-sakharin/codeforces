class Solution final {
private:
    template<class T>
    class DefaultMerger final {
    private:
        mutable queue<T> buffer{};

    public:
        template<class Iter>
        constexpr void operator()(
            Iter first,
            const Iter middle,
            const Iter last
        ) const noexcept {
            if (middle == last)
                return;

            auto second{middle};
            while (first < middle || !buffer.empty()) {
                if (first < middle)
                    buffer.push(move(*first));
                if (buffer.empty() || (second != last && *second < buffer.front())) {
                    *first = move(*second);
                    ++second;
                } else {
                    *first = move(buffer.front());
                    buffer.pop();
                }
                ++first;
            }
        }
    };

    template<class T>
    class RotateMerger final {
    public:
        template<class Iter>
        constexpr void operator()(
            const Iter first,
            Iter middle,
            const Iter last
        ) const noexcept {
            if (first == middle || middle == last)
                return;

            const auto leftSize{distance(first, middle)},
                rightSize{distance(middle, last)};
            Iter leftIter, rightIter;
            if (leftSize < rightSize) {
                rightIter = next(middle, (rightSize + 1) >> 1);
                leftIter = upper_bound(first, middle, *prev(rightIter));
                middle = prev(rotate(leftIter, middle, rightIter));
            } else {
                leftIter = next(first, (leftSize - 1) >> 1);
                rightIter = lower_bound(middle, last, *leftIter);
                middle = rotate(leftIter, middle, rightIter);
            }
            (*this)(first, leftIter, middle);
            (*this)(next(middle), rightIter, last);
        }
    };

    template<class Iter, class Merger>
    static constexpr void mergeSort(
        const Iter first,
        const Iter last,
        const Merger &merger
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
                merger(iter, middle, nextIter);
                n -= left + right;
                iter = nextIter;
            }
            width = width <= half ? width << 1 : size;
        }
    }

public:
    constexpr vector<int> sortArray(vector<int> &nums) const noexcept {
        mergeSort(nums.begin(), nums.end(), RotateMerger<int>{});
        return move(nums);
    }
};
