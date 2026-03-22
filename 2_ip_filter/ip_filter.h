typedef std::vector<std::string> Ip;

class IpFilter
{
public:
    IpFilter();

    //сортировка в обратном лексикографическом порядке
    void sortStd(std::vector<Ip> &ipPool);

    //сортировки по байтам
    std::vector<Ip> filterByte(std::vector<Ip> ipPool, int byte);
    std::vector<Ip> filterByte(std::vector<Ip> ipPool, int firstByte, int secondByte);
    std::vector<Ip> filterAnyByte(std::vector<Ip> ipPool, int byte);
};
