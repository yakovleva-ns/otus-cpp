#include "ip_pool_interaction.h"

IpPoolInteraction::IpPoolInteraction()
{}

Ip IpPoolInteraction::split(const std::string &str, char d)
{
    Ip ip;

    std::string::size_type start = 0;
    auto stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        ip.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    ip.push_back(str.substr(start));

    return ip;
}

IpPool IpPoolInteraction::readIpPool()
{
    IpPool ipPool;
    for(std::string line; std::getline(std::cin, line);)
    {
        auto v = split(line, '\t');
        Ip ip = split(v.at(0), '.');
        if (checkIp(ip))
            ipPool.push_back(ip);
    }
    return ipPool;
}
bool IpPoolInteraction::checkIp(Ip ip)
{
    if (ip.size() != 4)
        return false;
    else 
    {
        for (auto partIp : ip)
            if (! (stoi(partIp)>=0 ) && (stoi(partIp) <= 255) )
                return false;
     }
    return true;
}

void IpPoolInteraction::printIpPool(IpPool pool)
{
    for(auto ip = pool.cbegin(); ip != pool.cend(); ++ip)
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
