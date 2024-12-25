#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <exception>

namespace asio = boost::asio;

int main(int argc, char **argv)
{
    char *host = "8.8.8.8";
    char *port = "55010";
    asio::io_service service;
    asio::ip::tcp::resolver resolver(service);
    asio::ip::tcp::resolver::query query(asio::ip::tcp::v4(), host, port);
    asio::ip::tcp::resolver::iterator end, iter = resolver.resolve(query);

    asio::ip::tcp::endpoint server(iter->endpoint());
    std::cout << " connecting to " << server << std::endl;
    asio::ip::tcp::socket socket(service, asio::ip::tcp::v4());
    socket.connect(server);

    std::string msg = "client";
    asio::write(socket, asio::buffer(msg.c_str(), msg.size()));

    socket.shutdown(asio::ip::tcp::socket::shutdown_send);

    return 0;
}