#include <boost/assign.hpp>
#include <boost/rational.hpp>
#include <iterator>
#include <iostream>

int main(int argc, char const *argv[])
{
    const std::vector<std::string> list1 = boost::assign::list_of("a")("b")("c")("d")("e");
    for (auto i = list1.begin(); i != list1.end(); i++)
    {
        std::cout << " list_of " << (*i) << std::endl;
    }

    const std::map<std::string, boost::rational<int>> list2 = boost::assign::map_list_of //
        ("str1", boost::rational<int>(1, 2))                                             //
        ("str2", boost::rational<int>(1, 3))                                             //
        ("str3", boost::rational<int>(1, 4));

    for (auto i = list2.begin(); i != list2.end(); i++)
    {
        std::cout << " list_of " << (i->first) << " - " << (i->second) << std::endl;
    }

    std::cout << " sz " << boost::size(list2) << std::endl;

    // --
    using namespace boost::assign;
    std::vector<std::string> vector2;
    vector2 += "val1", "val2", "val3";
    for (auto i = vector2.begin(); i != vector2.end(); i++)
    {
        std::cout << " vector2 " << (*i) << std::endl;
    }

    return 0;
}
