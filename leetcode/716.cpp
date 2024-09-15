class MaxStack final {
private:
    map<int, stack<list<int>::const_iterator>> index{};
    list<int> values{};

public:
    constexpr void push(const int value) noexcept {
        values.push_back(value);
        index[value].push(--cend(values));
    }

    inline int pop() noexcept {
        const auto value{values.back()};
        const auto iter{index.find(value)};
        auto &iterStack{iter->second};
        values.pop_back();
        iterStack.pop();
        if (empty(iterStack))
            index.erase(iter);
        return value;
    }

    constexpr int top() const noexcept {
        return values.back();
    }

    inline int peekMax() const noexcept {
        return (--cend(index))->first;
    }

    inline int popMax() noexcept {
        const auto iter{--end(index)};
        const auto value{iter->first};
        auto &iterStack{iter->second};
        values.erase(iterStack.top());
        iterStack.pop();
        if (empty(iterStack))
            index.erase(iter);
        return value;
    }
};
