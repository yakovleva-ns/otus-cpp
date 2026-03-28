#pragma once
#include <vector>
#include <string>
#include <iostream>

using Ip = std::vector<std::string>;
using IpPool = std::vector<Ip>;

class IpPoolInteraction
{
public:
    IpPoolInteraction();

    IpPool readIpPool();
    void printIpPool(IpPool pool);
    
private:
    Ip split(const std::string &str, char d);
    bool checkIp(Ip ip);

};

