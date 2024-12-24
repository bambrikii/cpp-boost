#include <iostream>
#include <bitset>
#include <string>

int main()
{
    // 2 is true
    long a = 2;
    if (a)
    {
        std::cout << "true" << std::endl;
    }

    // resetting the bit with xor
    std::cout << std::bitset<8>(0b11 ^ 0b01) << std::endl;
    std::cout << std::bitset<8>(0b10 ^ 0b01) << std::endl;
    std::cout << std::bitset<8>(0b11 ^ 0b10) << std::endl;

    std::cout << std::bitset<8>(~0b010) << std::endl;

    // resetting the bit with & and negation
    std::cout << std::bitset<8>(0b11 & ~0b01) << std::endl;
    std::cout << std::bitset<8>(0b11 & ~0b00) << std::endl;

    // bit shift
    for (long i = -5; i < 5; i++)
    {
        std::cout << i << " " << std::bitset<8>(i) << " " << std::bitset<8>(i >> 0b01) << std::endl;
    }

    std::string str_arr[] = {"123", "456", "789"};
    for (auto str : str_arr)
    {
        std::cout << " before " << &str << " - " << str << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        str_arr[0] += "abcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyzabcdefghijklmnopqrstuvwzyz";
    }
    for (auto str : str_arr)
    {
        std::cout << " after  " << &str << " - " << str << " " << std::endl;
    }
}