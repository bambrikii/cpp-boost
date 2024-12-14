#include <iostream>
#include <string>
#include <set>

struct Cls1
{
    std::string prop1;
    std::string prop2;
    Cls1(std::string &&prop1, std::string &&prop2) : prop1(prop1), prop2(prop2) {}
};

bool operator<(const Cls1 &left, const Cls1 &right)
{
    // return left.prop1 < right.prop1;
    if (left.prop1 < right.prop1)
    {
        return true;
    };
    if (left.prop1 > right.prop1)
    {
        return false;
    }
    return left.prop2 < right.prop2;
}

int main(int argc, char const *argv[])
{
    std::multiset<Cls1> multiset1;
    multiset1.insert(Cls1("v1", "v1-2"));
    multiset1.insert(Cls1("v2", "v2-2"));
    multiset1.insert(Cls1("v3", "v3-2"));

    auto i1 = multiset1.lower_bound(Cls1("v1", ""));
    auto i2 = multiset1.upper_bound(Cls1("v2", ""));
    while (i1 != i2)
    {
        std::cout << " multiset lower_bound - upper_bound - " << i1->prop1 << " " << i1->prop2 << " " << std::endl;
        i1++;
    }
    return 0;
}
