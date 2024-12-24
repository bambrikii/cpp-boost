#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <iostream>

int main(int args, char **argv)
{
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