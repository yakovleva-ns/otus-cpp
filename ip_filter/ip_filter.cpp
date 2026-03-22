#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include "ip_filter.h"


IpFilter::IpFilter()
{};

bool needSwapIp(Ip &ip1, Ip &ip2)
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

std::vector<Ip> IpFilter::filterByte(std::vector<Ip> ipPool, int byte)
{
    std::vector<Ip> ipPoolSort;

    for(Ip ip : ipPool)
    {
        if (stoi(ip[0]) == byte)
            ipPoolSort.push_back(ip);
    }

    return ipPoolSort;
}

std::vector<Ip> IpFilter::filterByte(std::vector<Ip> ipPool, int firstByte, int secondByte)
{
    std::vector<Ip> ipPoolSort;

    for(Ip ip : ipPool)
    {
        if ((stoi(ip[0]) == 46) && (stoi(ip[1]) == 70))
            ipPoolSort.push_back(ip);
    }

    return ipPoolSort;
}

std::vector<Ip> IpFilter::filterAnyByte(std::vector<Ip> ipPool, int byte)
{
    std::vector<Ip> ipPoolSort;

    for(Ip ip : ipPool)
    {
        if ((stoi(ip[0]) == byte) || (stoi(ip[1]) == byte) || (stoi(ip[2]) == byte) || (stoi(ip[3]) == byte))
            ipPoolSort.push_back(ip);
    }

    return ipPoolSort;
}

void IpFilter::sortStd(std::vector<Ip> &ipPool)
{
    std::sort(ipPool.begin(), ipPool.end(), needSwapIp);
}
