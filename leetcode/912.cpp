class Solution final {
private:
    template<class Iter>
    static void merge(Iter first, const Iter middle, const Iter last) noexcept {
        if (middle == last)
            return;

        queue<typename iterator_traits<Iter>::value_type> buffer{};
        auto second{middle}, output{first};
        while (first != middle || !buffer.empty()) {
            if (first != middle) {
                buffer.push(move(*first));
                ++first;
            }
            if (buffer.empty() || (second != last && *second < buffer.front())) {
                *output = move(*second);
                ++second;
            } else {
                *output = move(buffer.front());
                buffer.pop();
            }
            ++output;
        }
    }

    template<class Iter>
    static void mergeSort(const Iter first, const Iter last) noexcept {
        const auto size{distance(first, last)}, half{size >> 1};
        typename iterator_traits<Iter>::difference_type width{1};
        while (width < size) {
            auto n{size};
            auto iter{first};
            while (iter != last) {
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
        return nums;
    }
};
