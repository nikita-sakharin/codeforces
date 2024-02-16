class Solution final {
private:
    template<class T>
    using Stack = stack<T, vector<T>>;

public:
    inline bool isValid(const string &str) const noexcept {
        Stack<char> s{};
        for (const auto &ch : str)
            if (ch == '(' || ch == '[' || ch == '{')
                s.push(ch);
            else if (!s.empty() && ((s.top() + 1) | 1) == ch)
                s.pop();
            else
                return false;
        return s.empty();
    }
};
