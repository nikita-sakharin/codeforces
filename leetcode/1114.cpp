class Foo final {
private:
    using uint = unsigned;

    condition_variable condition{};
    mutex sync{};
    uint counter{0};

public:
    inline void first(const function<void()> &printFirst) noexcept {
        unique_lock lock{sync};
        printFirst();
        ++counter;
        condition.notify_all();
    }

    inline void second(const function<void()> &printSecond) noexcept {
        unique_lock lock{sync};
        condition.wait(lock, [this]() constexpr noexcept -> bool {
            return counter == 1;
        });
        printSecond();
        ++counter;
        condition.notify_all();
    }

    inline void third(const function<void()> &printThird) noexcept {
        unique_lock lock{sync};
        condition.wait(lock, [this]() constexpr noexcept -> bool {
            return counter == 2;
        });
        printThird();
        ++counter;
        condition.notify_all();
    }
};
