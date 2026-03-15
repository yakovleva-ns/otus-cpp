#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

typedef std::vector<std::string> Ip;

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

bool needSwapIp(Ip ip1, Ip ip2)
{
    if ( (ip1.size() == 4) && (ip2.size() == 4) )
    {
        for (int i = 0 ; i <= 4 ; i++)
        {
            if (stoi(ip1[i]) < stoi(ip2[i]))
                return true;
        }
    }
    return false;
}


int partition(std::vector<Ip> ip_pool, int start, int end)
{
    Ip referenceIp = ip_pool[end];
    int index = start;

    for(int i = start; i < end; i++)
    {
        if (needSwapIp(ip_pool[i], referenceIp))
        {
            ip_pool[i].swap(ip_pool[index]);
            index ++;
        }
    }

    (referenceIp).swap(ip_pool[index]);
    return index;
}

void sortIpQuick(std::vector<Ip> ip_pool, int start, int end)
{
    if (start >= end)
        return;

    int pivot = partition(ip_pool, start, end);

    sortIpQuick(ip_pool, start, pivot-1);
    sortIpQuick(ip_pool, pivot+1, end);
}

void sortIpBubble(std::vector<Ip> ip_pool)
{
    for(int i = 0; i != ip_pool.size(); ++i)
    {
        for(auto ip = ip_pool.begin(); ip != ip_pool.end()-i; ++ip)
        {
            if (needSwapIp(*ip, *(ip+1)))
                (*ip).swap(*(ip+1));
        }
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        std::vector<Ip> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // reverse lexicographically sort
        
        //sortIpQuick(ip_pool, 0, ip_pool.size()-1);
        //sortIpBubble(ip_pool);
        std::sort(ip_pool.begin(), ip_pool.end(), needSwapIp);

        for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
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


        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
