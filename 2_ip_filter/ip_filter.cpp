#include <algorithm>
#include <cstdlib>

#include "ip_filter.h"


IpFilter::IpFilter()
{};

template< class T, class Alloc >
bool operator>=( const std::vector<T, Alloc>& ip1,
                 const std::vector<T, Alloc>& ip2 )
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
};

void IpFilter::sortStd(IpPool &ipPool)
{
    std::sort(ipPool.begin(), ipPool.end(),
         [](const Ip &ip1, const Ip &ip2) -> bool
         { 
            return (ip1 > ip2);
         });
}

IpPool IpFilter::filterByte(IpPool ipPool, std::vector<int> bytes)
{
    IpPool ipPoolSort;
    IpPool::iterator iterIp;
    if (bytes.size() <= 4)
    {
        for(unsigned int i = 0 ; i < bytes.size() ; i++)
        {
            iterIp = std::find_if(ipPool.begin(), ipPool.end(),
                                 [bytes, i](const Ip &ip) -> bool
                                 { 
                                    return (stoi(ip[i]) == bytes[i]);
                                 });
            if (iterIp == ipPool.end())
                break;
        }

        if (iterIp == ipPool.end())
            return ipPoolSort;

        for(auto ip = iterIp; ip < ipPool.end(); ip++)
        {
            if (stoi((*ip)[bytes.size()-1]) != bytes[bytes.size()-1])
                break;
                
            ipPoolSort.push_back(*ip);
         }
    }
    return ipPoolSort;
}

IpPool IpFilter::filterAnyByte(IpPool ipPool, int byte)
{
    IpPool ipPoolSort;

    for(Ip ip : ipPool)
    {
        if ((stoi(ip[0]) == byte) || (stoi(ip[1]) == byte) || (stoi(ip[2]) == byte) || (stoi(ip[3]) == byte))
            ipPoolSort.push_back(ip);
    }

    return ipPoolSort;
}
