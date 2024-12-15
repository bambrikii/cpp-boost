#include <boost/date_time.hpp>
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>
#include <iostream>

int main(int argc, char const *argv[])
{
    boost::gregorian::date dt1(2001, boost::gregorian::Jan, 1);
    std::cout << " date - " << dt1.day_of_week() << std::endl;

    boost::gregorian::date dt2 = boost::gregorian::from_simple_string("2001-01-01");
    std::cout << " date - " << dt2.day_of_week() << std::endl;
    std::cout << " date - " << (dt2 + boost::gregorian::weeks(1)).day_of_week() << std::endl;

    // -- periods

    boost::gregorian::date dt3(2001, boost::gregorian::Jan, 1);
    boost::gregorian::date dt4(2001, boost::gregorian::Feb, 1);
    boost::gregorian::date_period period1(dt3, dt4);

    std::cout << "period - " << (period1) << std::endl;

    // -- posix time

    boost::posix_time::ptime pt1(boost::gregorian::day_clock::universal_day(), boost::posix_time::hours(0));
    std::cout << "time - " << (pt1) << std::endl;

    // -- chrono

    boost::chrono::seconds sec1(1);
    std::cout << "seconds - " << (sec1) << std::endl;

    // -- timer

    // boost::timer::cpu_timer timer1;
    // timer1.stop();
    // std::cout << " timer " << timer1.format() << std::endl;

    return 0;
}
