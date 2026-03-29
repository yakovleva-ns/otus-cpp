#include <algorithm>
#include <cstdlib>

#include "ip_filter.h"


IpFilter::IpFilter()
{};

bool needSwap( const Ip ip1,const Ip ip2 )
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
   std::sort(ipPool.begin(), ipPool.end(), needSwap);
}

bool IpFilter::ipСompareBytes(Ip ip, std::vector<int> bytes)
{ 
    if (bytes.size() > 4)
        return false;

    unsigned int match = 0;
    for(unsigned int i = 0 ; i < bytes.size() ; i++)
    {
        if (stoi(ip[i]) == bytes[i])
            match++;
    }
    return (match == bytes.size());
}

IpPool IpFilter::filterByte(IpPool ipPool, std::vector<int> bytes)
{
    IpPool ipPoolSort;

    if (bytes.size() <= 4)
    {
        bool findFirstIp = false;

        for(auto ip : ipPool)
        {
            //ищем первое вхождение, если еще не найдено
            if (!findFirstIp)
                    findFirstIp = ipСompareBytes(ip, bytes);

            //первое вхождение найдено, берем элементы пока подходят
            if (findFirstIp)
            {
                 if (ipСompareBytes(ip, bytes))
                     ipPoolSort.push_back(ip);
                 else
                     return ipPoolSort;
            }
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
