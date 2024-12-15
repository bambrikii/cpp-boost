#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/phoenix/stl/algorithm.hpp>
#include <boost/phoenix/stl/container.hpp>

int main()
{
    namespace phx = boost::phoenix;
    double eX;
    auto x = phx::ref(eX);
    eX = 10.0;
    std::cout << " ref - " << (x + 1 / x)() << std::endl;                 // prints 10.1
    std::cout << " ref - " << ((x * x - x + 4) / (2 * x))() << std::endl; // prints 4.7

    // --

    using boost::phoenix::arg_names::arg1;
    std::vector<std::string> vec{"a1", "a2", "a3", "a4"};
    std::for_each(vec.begin(), vec.end(), std::cout << " for_each - " << arg1 << std::endl);

    // --

    std::vector<std::string> vector2{"b1", "b2", "b3", "b4"};
    auto finder = boost::phoenix::find(vector2, boost::phoenix::arg_names::arg1);
    auto it = finder("b3");
    std::cout << " finder - " << (*it) << std::endl;
}