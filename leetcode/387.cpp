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
        while (first != last) {
            const auto &value{*first};
            if (const auto iter{index.find(value)}; iter == cend(index)) {
                unique.push_back(first);
                index.emplace(value, --cend(unique));
            } else if (iter->second != cend(unique)) {
                unique.erase(iter->second);
                iter->second = cend(unique);
            }
            ++first;
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
