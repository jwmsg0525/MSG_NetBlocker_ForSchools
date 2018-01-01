#include <sarp.h>
#include <whitelisting.h>
#include <iostream>
#include <tins/tins.h>

#ifndef BLOCKING_H
#define BLOCKING_H

using namespace Tins;
class Blocking
{
public:
    WhiteListing * wit;
    string gatewayip;
    Blocking(WhiteListing * wit, string gatewayip);
    void bloc();
};

#endif // BLOCKING_H
