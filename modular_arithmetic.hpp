#ifndef MODULAR_ARITHMETIC_HPP
#define MODULAR_ARITHMETIC_HPP

#include <limits> // numeric_limits
#include <type_traits> // is_same_v, is_unsigned_v, remove_cv_t

template<typename T, T Mod>
class modular_arithmetic final {
public:
    constexpr modular_arithmetic() noexcept = default;
    constexpr modular_arithmetic(T) noexcept;
    constexpr modular_arithmetic(
        const modular_arithmetic &) noexcept = default;
    constexpr modular_arithmetic(
        modular_arithmetic &&) noexcept = default;
    constexpr modular_arithmetic &operator=(T) noexcept;
    constexpr modular_arithmetic &operator=(
        const modular_arithmetic &) noexcept = default;
    constexpr modular_arithmetic &operator=(
        modular_arithmetic &&) noexcept = default;
    constexpr ~modular_arithmetic() noexcept = default;

    constexpr T value() const noexcept;
    constexpr void value(T) noexcept;

    template<typename T_, T_ Mod_>
    friend constexpr modular_arithmetic<T_, Mod_> operator+(
        const modular_arithmetic<T_, Mod_> &,
        const modular_arithmetic<T_, Mod_> &
    ) noexcept;

private:
    static_assert(is_same_v<T, remove_cv_t<T>>, "");
    static_assert(is_unsigned_v<T>, "");
    static_assert(Mod >= static_cast<T>(2U), "");
    static_assert(numeric_limits<T>::max() / Mod >= Mod, "");

    T value_{};
};

template<typename T, T Mod>
constexpr modular_arithmetic<T, Mod>::modular_arithmetic(
    const T value
) noexcept : value_(value % Mod) {}

template<typename T, T Mod>
constexpr modular_arithmetic &modular_arithmetic<T, Mod>::operator=(
    const T value
) noexcept {
    value_ = value % Mod;
}

template<typename T, T Mod>
constexpr T modular_arithmetic<T, Mod>::value() const noexcept {
    return value_;
}

template<typename T, T Mod>
constexpr void modular_arithmetic<T, Mod>::value(const T value) noexcept {
    value_ = value % Mod;
}

template<typename T, T Mod>
constexpr modular_arithmetic<T, Mod> operator+(
    const modular_arithmetic<T, Mod> &val
) noexcept {
    assert(lhs.value_ < Mod);
    return val;
}

template<typename T, T Mod>
constexpr modular_arithmetic<T, Mod> operator-(
    const modular_arithmetic<T, Mod> &val
) noexcept {
    assert(lhs.value_ < Mod);
    return modular_arithmetic<T, Mod>(Mod - val.value_);
}

template<typename T, T Mod>
constexpr modular_arithmetic<T, Mod> operator+(
    const modular_arithmetic<T, Mod> &lhs,
    const modular_arithmetic<T, Mod> &rhs
) noexcept {
    assert(lhs.value_ < Mod && rhs.value_ < Mod);
    return modular_arithmetic<T, Mod>(lhs.value_ + rhs.value_);
}

template<typename T, T Mod>
constexpr modular_arithmetic<T, Mod> operator-(
    const modular_arithmetic<T, Mod> &lhs,
    const modular_arithmetic<T, Mod> &rhs
) noexcept {
    assert(lhs.value_ < Mod && rhs.value_ < Mod);
    return modular_arithmetic<T, Mod>(Mod - rhs.value_ + lhs.value_);
}

#endif
