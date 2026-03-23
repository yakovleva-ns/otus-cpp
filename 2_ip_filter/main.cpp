#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "ip_filter.h"

Ip split(const std::string &str, char d)
{
    Ip r;

    std::string::size_type start = 0;
    auto stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<Ip> readIpPool()
{
    std::vector<Ip> ipPool;
    for(std::string line; std::getline(std::cin, line);)
    {
        auto v = split(line, '\t');
        ipPool.push_back(split(v.at(0), '.'));
    }
    return ipPool;
}

void printIpPool(std::vector<Ip> ipPool)
{
    for(auto ip = ipPool.cbegin(); ip != ipPool.cend(); ++ip)
    {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv)
{
    try
    {
        auto ipPool =  readIpPool();

        IpFilter filter;
        filter.sortStd(ipPool);

        printIpPool(ipPool);
        printIpPool(filter.filterByte(ipPool, 1));
        printIpPool(filter.filterByte(ipPool, 46, 70));
        printIpPool(filter.filterAnyByte(ipPool, 46));
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
