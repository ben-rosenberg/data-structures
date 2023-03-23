#include <iostream>
#include <string>
#include <vector>
#include "array.h"
#include "dynamic_array.h"

struct Test {
    Test(int val) : a(val) {}
    int a;
};

int main()
{
    Array<int, 8> arr;
    std::cout << arr.size() << '\n';
    std::cout << arr[0] << '\n';

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i;
    }

    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';

    DynamicArray<int> defaultDyn;
    DynamicArray<int> sizeDyn(5);
    DynamicArray<std::string> sizeAndValDyn(5, "hello");

    std::cout << defaultDyn.size() << '\n';
    std::cout << defaultDyn.capacity() << '\n';
    std::cout << defaultDyn[0] << '\n';

    defaultDyn.print();
    sizeDyn.print();
    sizeAndValDyn.print();
}