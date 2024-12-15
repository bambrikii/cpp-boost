#include <iostream>
#include <string>
#include <set>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/indexed_by.hpp>

struct Cls1
{
    std::string prop1;
    std::string prop2;
    std::string prop3;
    Cls1(std::string &&prop01, std::string &&prop02, std::string &&prop03) : prop1(prop01), prop2(prop02), prop3(prop03) {}
};

bool operator<(const Cls1 &left, const Cls1 &right)
{
    // return left.prop1 < right.prop1;
    if (left.prop1 == right.prop1)
    {
        if (left.prop2 == right.prop2)
        {
            return left.prop3 < right.prop3;
        }

        return left.prop2 < right.prop2;
    }
    return left.prop1 < right.prop1;
}

int main(int argc, char const *argv[])
{
    std::multiset<Cls1> multiset1;
    multiset1.insert(Cls1("v1", "v1-2", "v3-1"));
    multiset1.insert(Cls1("v2", "v2-2", "v3-2"));
    multiset1.insert(Cls1("v3", "v3-2", "v3-3"));

    auto i1 = multiset1.lower_bound(Cls1("v1", "", ""));
    auto i2 = multiset1.upper_bound(Cls1("v2", "", ""));
    while (i1 != i2)
    {
        std::cout << " multiset lower_bound - upper_bound - " << i1->prop1 << " " << i1->prop2 << " " << std::endl;
        i1++;
    };

    // --

    // typedef boost::multi_index::ordered_non_unique<boost::multi_index::member<Cls1, std::string, &Cls1::prop1>> by_prop1;
    // typedef boost::multi_index::ordered_non_unique<boost::multi_index::member<Cls1, std::string, &Cls1::prop2>> by_prop2;
    // boost::multi_index_container<Cls1, boost::multi_index::indexed_by<by_prop1, by_prop2>> mi1;
    boost::multi_index_container<                                                                                //
        Cls1,                                                                                                    //
        boost::multi_index::indexed_by<                                                                          //
            boost::multi_index::ordered_non_unique<boost::multi_index::member<Cls1, std::string, &Cls1::prop1>>, //
            boost::multi_index::ordered_non_unique<boost::multi_index::member<Cls1, std::string, &Cls1::prop2>>, //
            boost::multi_index::ordered_non_unique<boost::multi_index::member<Cls1, std::string, &Cls1::prop3>>  //
            >                                                                                                    //
        >                                                                                                        //
        mi1;
    mi1.insert({"mi1", "1", "p3-1"});
    mi1.insert({"mi2", "2", "p3-2"});
    mi1.insert({"mi3", "mi2", "p3-3"});

    auto mi1iter1 = mi1.find("mi2");
    if (mi1iter1 != mi1.end())
    {
        std::cout << " mi1 found by prop1 - " << mi1iter1->prop1 << " - " << mi1iter1->prop2 << " - " << mi1iter1->prop3 << std::endl;
    }

    auto &m1_prop2 = mi1.get<1>();
    auto mi1iter2 = m1_prop2.find("2");
    if (mi1iter2 != m1_prop2.end())
    {
        std::cout << " mi1 found by prop2 - " << mi1iter2->prop1 << " - " << mi1iter2->prop2 << " - " << mi1iter2->prop3 << std::endl;
    }

    auto &m1_prop3 = mi1.get<2>();
    auto mi1iter3 = m1_prop3.find("p3-2");
    if (mi1iter3 != m1_prop3.end())
    {
        std::cout << " mi1 found by prop3 - " << mi1iter3->prop1 << " - " << mi1iter3->prop2 << " - " << mi1iter3->prop3 << std::endl;
    }

    return 0;
}
