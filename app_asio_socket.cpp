#include <boost/asio.hpp>
#include <iostream>
#include <exception>
#include <string>

namespace asio = boost::asio;

int main(int argc, char **argv)
{
    try
    {
        asio::io_service service;
        asio::ip::udp::resolver::query query(asio::ip::udp::v4(), "192.168.0.1", "32");
        asio::ip::udp::resolver resolver(service);
        auto iterator = resolver.resolve(query);
        asio::ip::udp::socket socket(service, asio::ip::udp::v4());

        asio::ip::udp::endpoint endpoint = iterator->endpoint();

        const char *msg = "hello";
        const std::string msg2 = "hello2";
        socket.send_to(asio::buffer(msg, strlen(msg)), endpoint);
        socket.send_to(asio::buffer(msg2.c_str(), msg2.size()), endpoint);
        socket.send_to(asio::buffer("\n", strlen("\n")), endpoint);
        char buffer[256];
        // size_t received = socket.receive_from(asio::buffer(buffer, sizeof(buffer)), endpoint);
        // buffer[received] = 0;
        // std::cout << " Received " << buffer << " from " << endpoint.address() << ":" << endpoint.port() << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cerr << "exception " << ex.what() << std::endl;
    }

    return 0;
}
