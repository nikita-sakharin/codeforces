class Foo final {
private:
    using uint = unsigned;

    class Linearizer final {
    private:
        condition_variable condition{};
        mutex sync{};
        uint counter{0};

    public:
        inline void operator()(
            const uint index,
            const function<void()> &func
        ) noexcept {
            unique_lock lock{sync};
            condition.wait(lock, [this, index]() constexpr noexcept -> bool {
                return counter == index;
            });
            func();
            ++counter;
            condition.notify_all();
        }
    };

    Linearizer linearizer{};

public:
    inline void first(const function<void()> &printFirst) noexcept {
        linearizer(0, printFirst);
    }

    inline void second(const function<void()> &printSecond) noexcept {
        linearizer(1, printSecond);
    }

    inline void third(const function<void()> &printThird) noexcept {
        linearizer(2, printThird);
    }
};
