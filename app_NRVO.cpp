#include <vector>
#include <iostream>

struct A
{
    A() { std::cout << "default ctor" << std::endl; }
    A(const A &a) { std::cout << "copy ctor" << std::endl; }
};

std::vector<A> *func()
{
    std::vector<A> *vec = new std::vector<A>();
    (*vec).push_back(A());
    std::cout << "new " << vec << std::endl;
    std::cout << "ref " << &vec << std::endl;
    return vec;
}

std::vector<A> func2()
{
    std::vector<A> vec;
    vec.push_back(A());
    std::cout << "ref " << &vec << std::endl;
    return vec;
}

int main(int argc, char *argv[])
{
    std::vector<A> *ret = func();
    std::cout << "new " << ret << std::endl;
    std::cout << "ref " << &ret << std::endl;

    std::vector<A> ret2 = func2();
    std::cout << "ref " << &ret2 << std::endl;
}
