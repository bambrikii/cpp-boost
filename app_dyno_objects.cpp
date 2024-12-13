#include <string>
#include <memory>
#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/ptr_unordered_map.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/make_shared.hpp>

class Cls1Base : boost::noncopyable // avoids making a sliced object when calling base's copy constructor
{
protected:
    std::string _str1;

public:
    Cls1Base(std::string &&str1) : _str1(std::move(str1))
    {
        std::cout << " creating Cls1Base " << _str1 << std::endl;
    }

public:
    virtual std::string method1()
    {
        return "default";
    }

    ~Cls1Base()
    {
        std::cout << " destroying Cls1Base " << _str1 << std::endl;
    }
};

class Cls1 : public Cls1Base
{
public:
    Cls1(std::string &&str1) : Cls1Base(std::move(str1))
    {
        std::cout << " creating Cls1& " << _str1 << std::endl;
    }
    Cls1(Cls1 *cls1) : Cls1Base(std::move(cls1->_str1))
    {
        std::cout << " creating Cls1* " << _str1 << std::endl;
    }
    std::string method1() override
    {
        return "cls1 " + _str1;
    }
    ~Cls1()
    {
        std::cout << " destroying Cls1 " << _str1 << std::endl;
    }
};

class Cls2 : public Cls1Base
{
public:
    Cls2(std::string &&str1) : Cls1Base(std::move(str1))
    {
        std::cout << " creating Cls2& " << _str1 << std::endl;
    }
    Cls2(Cls2 *cls2) : Cls1Base(std::move(cls2->_str1))
    {
        std::cout << " creating Cls1* " << _str1 << std::endl;
    }
    std::string method1() override
    {
        return "cls2 " + _str1;
    }
    ~Cls2()
    {
        std::cout << " destroying Cls2 " << _str1 << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    boost::ptr_vector<Cls1Base> ptr_vector1;
    ptr_vector1.push_back(new Cls1("name1"));
    ptr_vector1.push_back(new Cls2("name2"));
    for (auto iter = ptr_vector1.begin(); iter != ptr_vector1.end(); iter++)
    {
        std::cout << " ptr_vector1 " << (*iter).method1() << " " << std::endl;
    }

    // --
    // boost::ptr_multimap<std::string, boost::shared_ptr<Cls1Base>> ptr_multimap1;
    // ptr_multimap1["key1"] = boost::make_shared<Cls1>(new Cls1("val1"));
    // ptr_multimap1["key2"] = boost::make_shared<Cls2>(new Cls2("val2"));
    // auto ptr_multimap1_find_key1_iter = ptr_multimap1.find("key1");
    // if (ptr_multimap1_find_key1_iter != ptr_multimap1.end())
    // {
    //     std::cout << " ptr_multimap key "                         //
    //               << ptr_multimap1_find_key1_iter->first << " - " //
    //                                                               //   << ptr_multimap1_find_key1_iter->second->get()->method1() //
    //               << std::endl;
    // }

    boost::ptr_unordered_map<std::string, boost::shared_ptr<Cls1Base>> ptr_multimap1;
    ptr_multimap1["key1"] = boost::make_shared<Cls1>(std::move(new Cls1("val1")));
    auto ptr_multimap1_find_key1_iter = ptr_multimap1.find("key1");
    if (ptr_multimap1_find_key1_iter != ptr_multimap1.end())
    {
        std::cout << " ptr_multimap key "                                   //
                  << ptr_multimap1_find_key1_iter->first << " - "           //
                  << ptr_multimap1_find_key1_iter->second->get()->method1() //
                  << std::endl;
    }

    // --
    boost::ptr_vector<Cls1Base> ptr_vector2;
    ptr_vector2.push_back(new Cls1("vector2 - 1"));
    ptr_vector2.push_back(new Cls2("vector2 - 2"));

    boost::ptr_vector<Cls1Base> ptr_vector3;
    ptr_vector3.transfer(ptr_vector3.begin(), ptr_vector2.begin(), ptr_vector2);
    ptr_vector3.transfer(ptr_vector3.begin(), ptr_vector2.begin() + 1, ptr_vector2);
    for (auto iter = ptr_vector2.begin(); iter != ptr_vector2.end(); iter++)
    {
        std::cout << " ptr_vector2 " << (*iter).method1() << " " << std::endl;
    }
    for (auto iter = ptr_vector3.begin(); iter != ptr_vector3.end(); iter++)
    {
        std::cout << " ptr_vector3 " << (*iter).method1() << " " << std::endl;
    }

    return 0;
}
