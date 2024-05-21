class Solution final {
private:
    template<class Iter>
    static void merge(Iter first, const Iter middle, const Iter last) noexcept {
        queue<typename iterator_traits<Iter>::value_type> buffer{};
        Iter second{middle};
        while ((first != middle || !buffer.empty()) && second != last) {
            if (first != middle)
                buffer.push(move(*first));
            if (*second < buffer.front())
                *first++ = move(*second++);
            else {
                *first++ = move(buffer.front());
                buffer.pop();
            }
        }
        while (!buffer.empty()) {
            *first++ = move(buffer.front());
            buffer.pop();
        }
    }

    template<class Iter>
    static void mergeSort(const Iter first, const Iter last) noexcept {
        const auto size{distance(first, last)}, half{size >> 1};
        ptrdiff_t width{1};
        while (width < size) {
            const auto nextWidth{width <= half ? width << 1 : size};
            auto n{size};
            auto iter{first};
            while (iter != last) {
                const auto left{min(width, n)}, right{min(width, n - left)}; // TODO
                const auto middle{next(iter, left)},
                    nextIter{next(middle, right)};
                merge(iter, middle, nextIter);
                n -= left + right;
                iter = nextIter;
            }
            width = nextWidth;
        }
    }

public:
    inline vector<int> sortArray(vector<int> &nums) const noexcept {
        mergeSort(nums.begin(), nums.end());
        return nums;
    }
};
