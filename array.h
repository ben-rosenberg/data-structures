#include <type_traits>

template <typename T, size_t Size>
class Array {
    static_assert(std::is_default_constructible_v<T>, "Templated type must be default-constructible");
public:
    Array() : _data{T()}, _size(Size) {}
    Array(T init_val) : _data{T(init_val)}, _size(Size) {}

    // read
    [[nodiscard]] const T& operator[](const size_t i) const {
        return _data[i];
    }

    // write
    [[nodiscard]] T& operator[](const size_t i) {
        return _data[i];
    } 

    [[nodiscard]] constexpr size_t size() const {
        return Size;
    }

private:
    T _data[Size];
    size_t _size;
};