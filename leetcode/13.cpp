class Solution final {
    static constexpr int letterToInt(const char ch) noexcept {
        switch (ch) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                terminate();
        }
    }

public:
    constexpr int romanToInt(const string &str) const noexcept {
        auto result{0}, prevInt{0};
        for (const auto &chr : str) {
            const auto toInt{letterToInt(chr)};
            if (toInt < prevInt)
                result -= toInt;
            else
                result += toInt;
            prevInt = toInt;
        }
        return result;
    }
};
