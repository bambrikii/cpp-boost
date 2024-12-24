#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <iostream>

int main(int args, char **argv)
{
    boost::asio::io_service svc;
    svc.dispatch([]()
                 { std::cout << "dispatch" << std::endl; });
    svc.post([]()
             { std::cout << "post" << std::endl; });
    svc.poll();
    // svc.run();
    return 0;
}