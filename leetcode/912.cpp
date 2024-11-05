class Solution final {
private:
    template<class Iter>
    using Value = iterator_traits<Iter>::value_type;

    template<class Iter>
    static constexpr auto
        category{typename iterator_traits<Iter>::iterator_category()};

    template<class Iter, class Container = deque<Value<Iter>>>
    class DefaultMerger final {
    private:
        mutable queue<Value<Iter>, Container> buffer{};

        constexpr void operator()(
            Iter first,
            const Iter middle,
            const Iter last,
            const forward_iterator_tag
        ) const noexcept {
            if (first == middle || middle == last)
                return;

            auto second{middle};
            auto leftNonEmpty{true};
            do {
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
            } while (leftNonEmpty || !empty(buffer));
        }

        constexpr void operator()(
            Iter first,
            const Iter middle,
            const Iter last,
            const random_access_iterator_tag
        ) const noexcept {
            if (first == middle || middle == last)
                return;

            auto second{middle};
            do {
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
            } while (first < middle || !empty(buffer));
        }

    public:
        constexpr void operator()(
            Iter first,
            const Iter middle,
            const Iter last
        ) const noexcept {
            (*this)(first, middle, last, category<Iter>);
        }
    };

    template<class Iter, class Container = vector<tuple<Iter, Iter, Iter>>>
    class RotateMerger final {
    private:
        mutable stack<tuple<Iter, Iter, Iter>, Container> lifo{};

    public:
        constexpr void operator()(
            Iter first,
            Iter middle,
            Iter last
        ) const noexcept {
            lifo.emplace(first, middle, last);
            do {
                tie(first, middle, last) = lifo.top();
                lifo.pop();
                if (first == middle || middle == last)
                    continue;

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
                lifo.emplace(first, leftIter, middle);
                lifo.emplace(next(middle), rightIter, last);
            } while (!empty(lifo));
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
    inline vector<int> sortArray(vector<int> &nums) const noexcept {
        mergeSort(begin(nums), end(nums), RotateMerger<vector<int>::iterator>{});
        return move(nums);
    }
};
