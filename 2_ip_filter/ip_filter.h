#include "ip_pool_interaction.h"

class IpFilter
{
public:
    IpFilter();

    //сортировка в обратном лексикографическом порядке
    void sortStd(std::vector<Ip> &ipPool);

    //сортировки по байтам
    IpPool filterByte(IpPool ipPool, std::vector<unsigned int> bytes);
    IpPool filterAnyByte(IpPool ipPool, unsigned int byte);
};
