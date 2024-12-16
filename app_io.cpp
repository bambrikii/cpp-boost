#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int fh1 = open("file1.csv", O_RDONLY);
    boost::iostreams::file_descriptor_source fd1(             //
        fh1,                                                  //
        boost::iostreams::file_descriptor_flags::close_handle //
    );                                                        //

    boost::iostreams::stream<boost::iostreams::file_descriptor_source> in1(fd1);
    std::string line;
    while (std::getline(in1, line))
    {
        std::cout << line << std::endl;
    }

    return 0;
}
