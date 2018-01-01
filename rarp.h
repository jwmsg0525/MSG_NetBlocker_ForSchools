#include <string.h>
#include <iostream>
#include <map>
#include <tins/tins.h>
#include <whitelisting.h>
#include <logging.h>
#ifndef RARP_H
#define RARP_H

using namespace std;
using namespace Tins;
class RARP
{

public:

    WhiteListing * wit;
    Logging *lg;
    Sniffer snif = Sniffer(NetworkInterface::default_interface().name());
    RARP(WhiteListing *wit, Logging *lg);
    bool ARP_Call_Back(const PDU& pdu);
    void ricevARP();
};

#endif // RARP_H
