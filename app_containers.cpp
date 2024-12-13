#include <iostream>
#include <string>
#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/slist.hpp>
#include <boost/container/stable_vector.hpp>

int main(int argc, char **argv)
{
    boost::container::flat_map<std::string, std::string> map1;
    map1["key1"] = "val1";

    for (auto kv : map1)
    {
        std::cout << "map1 " << kv.first << " - " << kv.second << "" << std::endl;
    }

    // ---

    boost::container::flat_set<std::string> set1;
    set1.insert("val1");

    for (auto val : set1)
    {
        std::cout << "set1 " << val << "" << std::endl;
    }

    // ---

    boost::container::slist<std::string> slist1;
    slist1.push_front("val1");
    slist1.push_front("val2");
    slist1.push_front("val3");
    slist1.emplace_after(slist1.begin(), "val4-after-beging");
    slist1.emplace_after(slist1.end(), "val5-after-end");

    for (auto val : slist1)
    {
        std::cout << "slist1 " << val << "" << std::endl;
    }

    boost::container::slist<std::string>::iterator slist1_begin = slist1.begin();
    boost::container::slist<std::string>::iterator slist1_end = slist1.end();

    std::cout << " slist1 "                      //
              << "\n - front " << slist1.front() //
              << "\n - begin " << &slist1_begin
              << "\n - end " << &slist1_end
              << "\n - size " << sizeof(slist1)
              << "\n - size " << sizeof(std::string)
              << "\n - size " << sizeof(slist1_begin)
              << "\n - size " << sizeof(slist1_end)
              << std::endl;
    boost::container::slist<std::string> slist2;
    slist2.push_front("val6-slist2");
    slist2.splice(slist2.begin(), slist1, slist1.begin(), slist1.end());
    for (auto val : slist2)
    {
        std::cout << "slist2-spliced " << val << "" << std::endl;
    }

    // ---

    boost::container::stable_vector<std::string> stable_vector1;
    stable_vector1.insert(stable_vector1.end(), "val1");
    stable_vector1.insert(stable_vector1.end(), "val2");
    stable_vector1.insert(stable_vector1.end(), "val3");
    for (auto val : stable_vector1)
    {
        std::cout << "stable_vector1 " << val << "" << std::endl;
    }

    return 0;
}