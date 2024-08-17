class MaxStack final {
private:
    map<int, stack<list<int>::const_iterator>> index{};
    list<int> values{};

public:
    inline void push(const int value) noexcept {
        values.push_back(value);
        index[value].push(--values.cend());
    }

    inline int pop() noexcept {
        const auto value{values.back()};
        values.pop_back();
        const auto iter{index.find(value)};
        iter->second.pop();
        if (iter->second.empty())
            index.erase(iter);
        return value;
    }

    inline int top() const noexcept {
        return values.back();
    }

    inline int peekMax() const noexcept {
        return (--index.cend())->first;
    }

    inline int popMax() noexcept {
        const auto iter{--index.end()};
        const auto value{iter->first};
        values.erase(iter->second.top());
        iter->second.pop();
        if (iter->second.empty())
            index.erase(iter);
        return value;
    }
};
