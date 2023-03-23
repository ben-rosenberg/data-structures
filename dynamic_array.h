#include <iostream>
#include <utility>

template <typename T>
class DynamicArray
{
    static constexpr size_t DEFAULT_CAPACITY = 2;
public:
    DynamicArray()
        : _size(0), _capacity(DEFAULT_CAPACITY), _data(new T[DEFAULT_CAPACITY]{}) {}

    DynamicArray(size_t size)
        : _size(size), _capacity(size + size / 2), _data(new T[size + size / 2]{}) {}
    
    DynamicArray(size_t size, const T& initVal)
            : _size(size), _capacity(size + size / 2) {
        _data = new T[size + size / 2];

        for (size_t i = 0; i < size; ++i)
            _data[i] = initVal;
    }
    
    void pushBack(const T& value) {
        if (_size + 1 > _capacity)
            reAlloc(_capacity + _capacity / 2);
        
        _data[_size] = value;
        ++_size;
    }

    void pushBack(T&& value) {
        if (_size + 1 > _capacity)
            reAlloc(_capacity + _capacity / 2);
        
        _data[_size] = std::move(value);
    }

    const T& operator[](size_t i) const { return _data[i]; }
    T& operator[](size_t i) { return _data[i]; }

    void print(char separator = ' ') const {
        std::cout << "{ ";
        for (size_t i = 0; i < _size; ++i)
            std::cout << _data[i] << separator;
        
        std::cout << " }\n";
    }

    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }

private:
    void reAlloc(const size_t newCapacity) {
        T* new_block = new T[newCapacity];

        if (newCapacity < _size)
            _size = newCapacity;

        for (size_t i = 0; i < _size; ++i)
            new_block[i] = _data[i];

        delete[] _data;
        _data = new_block;
        _capacity = newCapacity;
    }

private:
    T* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;
};