#include <iostream>
#include <tins/tins.h>
#include <thread>
#ifndef SARP_
#define SARP_H

using namespace std;

class SARP
{
public:

    SARP();
    void sendRQ(string dstip);
    void sendRS(string dstip,string srcip, string dstmac, string srcmac);
    void sndBand(string startbnd , string endband );
};

#endif // SARP_H
