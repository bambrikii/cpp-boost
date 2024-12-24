#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
  std::vector<std::string> v1{"str1", "str2", "str3"};

  // thread
  boost::thread([](const std::vector<std::string> &val1)
                { 
                    for(auto i=val1.begin(); i!=val1.end();i++) {
                    std::cout << (*i) << std::endl;
                    } }, v1);

  // thread group
  boost::thread_group pool;
  pool.create_thread([]()
                     { std::cout << "pool" << std::endl; });
  pool.join_all();

  return 0;
}
