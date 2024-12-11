#include <iostream>
#include <memory>
#include <boost/regex.hpp>
#include <boost/regex/config.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/tokenizer.hpp>
#include <regex>
#include <string>
#include <algorithm>
#include <fstream>

void print_match(std::string &str)
{
    boost::regex e("^.*(\\d).*$");
    bool matches = boost::regex_match(str, e);
    std::cout << "matches = " << matches << std::endl;
}

void print_search(std::string &str)
{
    std::string::const_iterator start = str.begin();
    std::string::const_iterator end = str.end();
    boost::regex re2("\\w");
    boost::match_results<std::string::const_iterator> mr2;
    while (boost::regex_search(start, end, mr2, re2))
    {
        start = mr2[0].second;
        std::cout
            << " "
            << mr2[0].matched
            << " - "
            << mr2[0]
            << std::endl;
    }
}

void print_to_upper(std::string &str)
{
    std::cout << "upper    " << boost::algorithm::to_upper_copy(str, std::locale()) << std::endl;
    std::cout << "original " << str << std::endl;
}

std::vector<std::vector<std::string>> read_csv(std::string file_name)
{
    std::vector<std::vector<std::string>> rows;
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cout << "failed to open file \"" << file_name << "\" " << std::endl;
        return rows;
    }
    std::cout << "file \"" << file_name << "\" is open " << std::endl;

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::string> row;
        boost::tokenizer<boost::escaped_list_separator<char>> tokenizer(line);
        for (const auto &columns : tokenizer)
        {
            row.push_back(columns);
        }
        rows.push_back(row);
    }
    return rows;
}

void print_csv(const std::vector<std::vector<std::string>> rows)
{
    for (auto row : rows)
    {
        for (auto col : row)
        {
            std::cout << " " << col << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::string str = "some-string1";

    print_match(str);
    print_search(str);
    print_to_upper(str);
    const auto &csv = read_csv("file1.csv");
    print_csv(csv);

    return 1;
}
