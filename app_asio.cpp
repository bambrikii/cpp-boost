#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <string>

struct struct1
{
    int prop1;
    int prop2;
    std::string str1;
};

struct struct2
{
    int prop3;
    struct1 prop4;
};

int main(int args, char **argv)
{
    struct2 str2 = {1, 2, 3, "q"};
    std::cout << "str" << str2.prop4.str1 << std::endl;
    // io service
    boost::asio::io_service svc;
    svc.dispatch([]()
                 { std::cout << "dispatch" << std::endl; });
    svc.post([]()
             { std::cout << "post" << std::endl; });
    svc.poll();
    // svc.run();

    // strands
    boost::asio::io_service svc2;
    boost::asio::io_service::strand strand(svc2);
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        svc2.post(strand.wrap([&counter, i]()
                              { std::cout << "strand " << counter++ << " - " << i << std::endl; }));
    }

    svc2.poll();
    return 0;
}