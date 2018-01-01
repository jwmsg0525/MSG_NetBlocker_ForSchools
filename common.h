#include <iostream>
#include <stdio.h>
#include <string.h>
#include <tins/tins.h>
#include <pcap.h>

#ifndef COMMON_H
#define COMMON_H

#endif // COMMON_H

using namespace Tins;
using namespace std;

Sniffer sniffer;
NetworkInterface interface;
IPv4Address myaddress;
EthernetII::address_type myMAC;

