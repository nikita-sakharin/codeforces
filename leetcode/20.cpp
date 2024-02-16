class Solution final {
private:
    template<class T>
    using Stack = stack<T, vector<T>>;

    static constexpr char getClosing(const char opening) noexcept {
        return (opening + 1) | 1;
    }

public:
    inline bool isValid(const string &str) const noexcept {
        Stack<char> s{};
        for (const auto &ch : str)
            if (ch == '(' || ch == '[' || ch == '{')
                s.push(ch);
            else if (s.empty() || getClosing(s.top()) != ch)
                return false;
            else
                s.pop();
        return s.empty();
    }
};
