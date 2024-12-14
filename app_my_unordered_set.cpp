#include <iostream>
#include <string>
#include <boost/unordered_set.hpp>
#include <boost/functional/hash.hpp>

struct Cls1
{
    std::string prop1;
    std::string prop2;
    Cls1(std::string &&prop1, std::string &&prop2) : prop1(prop1), prop2(prop2)
    {
    }
};

bool operator==(const Cls1 &left, const Cls1 &right)
{
    return left.prop1 == right.prop1 && left.prop2 == right.prop2;
}

namespace boost
{
    template <>
    struct hash<Cls1>
    {
        size_t operator()(const Cls1 &cls) const
        {
            size_t hash = 0;
            boost::hash_combine(hash, boost::hash_value(cls.prop1));
            boost::hash_combine(hash, boost::hash_value(cls.prop2));
            return hash;
        }
    };
};

int main(int argc, char const *argv[])
{
    boost::unordered_set<Cls1> unordered_set1;
    unordered_set1.insert(Cls1("val1", "val1-2"));
    unordered_set1.insert(Cls1("val2", "val2-2"));
    unordered_set1.insert(Cls1("val3", "val3-2"));
    for (auto i = unordered_set1.begin(); i != unordered_set1.end(); i++)
    {
        std::cout << " unordered set " << i->prop1 << ", " << i->prop2 << std::endl;
    }

    auto unordered_set_found = unordered_set1.find(Cls1("val2", "val2-2"));
    if (unordered_set_found != unordered_set1.end())
    {
        std::cout << " unordered set find " << unordered_set_found->prop1 << ", " << unordered_set_found->prop2 << std::endl;
    }

    return 0;
}
