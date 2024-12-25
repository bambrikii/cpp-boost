// #define BOOST_ASIO_DISABLE_BOOST_COROUTINE 1

#include <iostream>
// #include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
// #include <boost/date_time.hpp>
#include <boost/bind.hpp>
// #include <boost/parameter.hpp>

void my_wait_1(boost::asio::yield_context &yield_ctx, boost::asio::io_service &service)
{
    boost::asio::deadline_timer timer(service);
    timer.expires_from_now(boost::posix_time::seconds(5));
    timer.async_wait(yield_ctx);
    std::cout << "wait complete" << std::endl;
}

int main(int argc, char **argv)
{
    boost::asio::io_service service;
    // boost::asio::spawn(&service, boost::bind(my_wait_1, ::_1, boost::ref(service)));
    // boost::asio::spawn(&service, boost::bind(my_wait_1, ::_1, boost::ref(service)));
    boost::asio::spawn(&service, [&service](boost::asio::yield_context yield_ctx)
                       { my_wait_1(yield_ctx, service); } /*, boost::asio::detached*/);

    return 0;
}