#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char **argv)
{
    // endpoints
    std::string host = "8.8.8.8";
    int port = 32;

    try
    {
        boost::asio::io_service service;
        boost::asio::ip::tcp::endpoint endpoint(         //
            boost::asio::ip::address::from_string(host), //
            port                                         //
        );                                               //

        boost::asio::ip::tcp::resolver resolver(service);
        boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(endpoint), end;
        while (iterator != end)
        {
            std::cout << " host " << iterator->host_name() << " " << " " << iterator->service_name() << std::endl;
            iterator++;
        }
    }
    catch (std::exception &ex)
    {
        std::cerr << " error " << ex.what() << std::endl;
    }
    return 0;
}