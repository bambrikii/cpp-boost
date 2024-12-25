#include <boost/asio.hpp>
#include <iostream>

namespace asio = boost::asio;
namespace sys = boost::system;

const size_t MAXBUF = 256;

class UdpServer
{
private:
    asio::ip::udp::socket socket;
    asio::ip::udp::endpoint endpoint;
    char buffer[MAXBUF];

public:
    UdpServer(asio::io_service &service, unsigned short port) :                                                        //
                                                                socket(                                                //
                                                                    service,                                           //
                                                                    asio::ip::udp::endpoint(asio::ip::udp::v4(), port) //
                                                                    )                                                  //
    {
        wait();
    }

    void wait()
    {
        socket.async_receive_from( //
            asio::buffer(buffer, MAXBUF),
            endpoint,
            [this](const sys::error_code &error_code, size_t size)
            {
                std::cout << "received " << buffer << " - " << endpoint << std::endl;
            });
        const char *msg = "hello from server";
        socket.async_send_to( //
            asio::buffer(msg, strlen(msg)),
            endpoint,
            [this](const sys::error_code &error_code, size_t size)
            {
                //
            });
    }
};

int main(int argv, char **argc)
{
    asio::io_service service;
    UdpServer server(service, 55000);
    server.wait();
    return 0;
}