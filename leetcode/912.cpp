class Solution final {
private:
    template<class Iter>
    static constexpr auto
        category{typename iterator_traits<Iter>::iterator_category()};

    template<class T, class Container = deque<T>>
    class DefaultMerger final {
    private:
        mutable queue<T, Container> buffer{};

        template<class Iter>
        constexpr void operator()(
            Iter first,
            const Iter middle,
            const Iter last,
            const forward_iterator_tag
        ) const noexcept {
            if (middle == last)
                return;

            auto second{middle};
            auto leftNonEmpty{first != middle};
            while (leftNonEmpty || !empty(buffer)) {
                if (leftNonEmpty)
                    buffer.push(move(*first));
                if (empty(buffer) || (second != last && *second < buffer.front())) {
                    *first = move(*second);
                    ++second;
                } else {
                    *first = move(buffer.front());
                    buffer.pop();
                }
                ++first;
                leftNonEmpty = leftNonEmpty && first != middle;
            }
        }

        template<class Iter>
        constexpr void operator()(
            Iter first,
            const Iter middle,
            const Iter last,
            const random_access_iterator_tag
        ) const noexcept {
            if (middle == last)
                return;

            auto second{middle};
            while (first < middle || !empty(buffer)) {
                if (first < middle)
                    buffer.push(move(*first));
                if (empty(buffer) || (second != last && *second < buffer.front())) {
                    *first = move(*second);
                    ++second;
                } else {
                    *first = move(buffer.front());
                    buffer.pop();
                }
                ++first;
            }
        }

    public:
        template<class Iter>
        constexpr void operator()(
            Iter first,
            const Iter middle,
            const Iter last
        ) const noexcept {
            (*this)(first, middle, last, category<Iter>);
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
        Difference step{1};
        while (step < size) {
            auto length{size};
            auto iter{first};
            while (length > 0) {
                const auto
                    left{min(step, length)},
                    right{min(step, length - left)};
                const auto middle{next(iter, left)},
                    nextIter{next(middle, right)};
                merger(iter, middle, nextIter);
                length -= left + right;
                iter = nextIter;
            }
            step = step <= half ? step << 1 : size;
        }
    }

public:
    constexpr vector<int> sortArray(vector<int> &nums) const noexcept {
        mergeSort(begin(nums), end(nums), RotateMerger<int>{});
        return move(nums);
    }
};
