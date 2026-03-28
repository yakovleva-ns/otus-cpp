#include <cassert>
#include <cstdlib>
#include "ip_filter.h"


int main(int /*argc*/, char** /*argv*/)
{
    try
    {
        IpPoolInteraction interactionPool;
        IpPool ipPool = interactionPool.readIpPool();

        IpFilter filter;
        filter.sortStd(ipPool);

        interactionPool.printIpPool(ipPool);
        interactionPool.printIpPool(filter.filterByte(ipPool, {1}));
        interactionPool.printIpPool(filter.filterByte(ipPool, {46, 70}));
        interactionPool.printIpPool(filter.filterAnyByte(ipPool, 46));
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
