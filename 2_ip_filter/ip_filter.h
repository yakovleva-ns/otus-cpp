#include "ip_pool_interaction.h"

class IpFilter
{
public:
    IpFilter();

    //сортировка в обратном лексикографическом порядке
    void sortStd(IpPool &ipPool);

    //сортировки по байтам
    IpPool filterByte(IpPool ipPool, std::vector<int> bytes);
    IpPool filterAnyByte(IpPool ipPool, int byte);
};
