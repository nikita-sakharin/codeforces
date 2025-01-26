class Solution final {
private:
    template<class Iter>
    static constexpr Iter firstUnique(
        Iter first,
        const Iter last
    ) noexcept {
        using Value = iterator_traits<Iter>::value_type;
        using ConstIterator = list<Iter>::const_iterator;

        list<Iter> unique{};
        unordered_map<Value, ConstIterator> index{};
        const auto uniqueLast{cend(unique)};
        const auto indexLast{cend(index)};
        for (; first != last; ++first) {
            const auto &value{*first};
            if (const auto iter{index.find(value)}; iter == indexLast) {
                unique.push_back(first);
                index.emplace(value, prev(uniqueLast));
            } else if (iter->second != uniqueLast) {
                unique.erase(iter->second);
                iter->second = uniqueLast;
            }
        }

        return empty(unique) ? last : unique.front();
    }

public:
    constexpr int firstUniqChar(const string &s) const noexcept {
        const auto first{cbegin(s)}, last{cend(s)},
            iter{firstUnique(first, last)};
        return iter == last ? -1 : int(iter - first);
    }
};
