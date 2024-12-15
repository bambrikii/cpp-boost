// #define BOOST_NO_SCOPED_ENUMS
#include <boost/filesystem.hpp>
// #undef BOOST_NO_SCOPED_ENUMS

#include <iostream>

int main(int argc, char const *argv[])
{
    // --

    boost::filesystem::path cwd = boost::filesystem::current_path();
    std::cout << "cwd " << cwd.generic_string() << std::endl;
    std::cout << "cwd " << cwd.string() << std::endl;
    std::cout << "cwd " << cwd << std::endl;

    // boost::filesystem::create_directory("./some-dir");

    // -- path

    boost::filesystem::path file1("app_fs.cpp");
    std::cout << "file1 " << file1.generic_string() << std::endl;
    std::cout << "file1 " << file1.string() << std::endl;
    std::cout << "file1 " << file1 << std::endl;

    // -- list directory
    boost::filesystem::path p2(".");
    // boost::filesystem::directory_iterator di1(p2), end;
    // std::for_each(di1, end, [](const boost::filesystem::directory_entry &entry)
    //               {
    //                   std::cout << " " << entry.path().string() << std::endl; //
    //               });

    return 0;
}
