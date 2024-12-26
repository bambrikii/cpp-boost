#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

namespace asio = boost::asio;

typedef boost::shared_ptr<asio::ip::tcp::socket> socket_ptr;

int main(int argc, char **argv)
{
    const unsigned short port = 55010;

    asio::io_service service;
    asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);
    asio::ip::tcp::acceptor acceptor(service, endpoint);
    while (true)
    {
        socket_ptr socket(new asio::ip::tcp::socket(service));
        acceptor.accept(*socket);
        boost::thread([socket]()
                      { std::cout << " received" << socket->remote_endpoint() << std::endl; });

        boost::system::error_code error_code;
        char buffer[BUFSIZ];
        size_t size = read(*socket, asio::buffer(buffer, BUFSIZ), error_code);
        if (!error_code || error_code == asio::error::eof)
        {
            const char *error_message = "error";
            write(*socket, asio::buffer(error_message, BUFSIZ));
            socket->close();
        }
    }

    return 0;
}