class Solution final {
public:
    int compress(vector<char> &chars) const noexcept {
        const auto size{chars.size()};
        const auto ptrEnd{chars.data() + size};
        auto ptr{chars.data() + 1};
        size_t cnt{1};
        for (size_t i{1}; i < size; ++i) {
            if (chars[i - 1] != chars[i]) {
                if (cnt > 1)
                    ptr = to_chars(ptr, ptrEnd, cnt).ptr;
                cnt = 0;
                *ptr++ = chars[i];
            }
            ++cnt;
        }
        if (cnt > 1)
            ptr = to_chars(ptr, ptrEnd, cnt).ptr;
        chars.resize(ptr - chars.data());
        return static_cast<int>(chars.size());
    }
};
