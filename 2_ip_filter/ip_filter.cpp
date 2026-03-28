#include <algorithm>
#include <cstdlib>

#include "ip_filter.h"


IpFilter::IpFilter()
{};

bool operator > ( const Ip &ip1, const Ip &ip2)
{
     if (stoi(ip1[0]) > stoi(ip2[0]))
            return true;

    if (stoi(ip1[0]) == stoi(ip2[0]))
        if (stoi(ip1[1]) > stoi(ip2[1]))
            return true;

    if (stoi(ip1[0]) == stoi(ip2[0]))
    if (stoi(ip1[1]) == stoi(ip2[1]))
        if (stoi(ip1[2]) > stoi(ip2[2]))
            return true;

    if (stoi(ip1[0]) == stoi(ip2[0]))
    if (stoi(ip1[1]) == stoi(ip2[1]))
    if (stoi(ip1[2]) == stoi(ip2[2]))
        if (stoi(ip1[3]) > stoi(ip2[3]))
            return true;

    return false;
}

void IpFilter::sortStd(std::vector<Ip> &ipPool)
{
    std::sort(ipPool.begin(), ipPool.end(),
         [](const Ip &ip1, const Ip &ip2) -> bool
         { 
            return (ip1 > ip2);
         });
}

IpPool IpFilter::filterByte(IpPool ipPool, std::vector<unsigned int> bytes)
{
    IpPool ipPoolSort;

    if (bytes.size() <= 4)
    {
        for(Ip ip : ipPool)
        {
            bool needIp = true;
            for( auto i = 0 ; i < bytes.size() ; i++)
            {
                if (stoi(ip[i]) != bytes[i])
                    needIp = false;
            }
            if (needIp)
                ipPoolSort.push_back(ip);
        }
    }
    return ipPoolSort;
}

IpPool IpFilter::filterAnyByte(IpPool ipPool, unsigned int byte)
{
    IpPool ipPoolSort;

    for(Ip ip : ipPool)
    {
        if ((stoi(ip[0]) == byte) || (stoi(ip[1]) == byte) || (stoi(ip[2]) == byte) || (stoi(ip[3]) == byte))
            ipPoolSort.push_back(ip);
    }

    return ipPoolSort;
}
