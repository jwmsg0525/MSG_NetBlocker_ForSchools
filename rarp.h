#include <string.h>
#include <iostream>
#include <map>

#ifndef RARP_H
#define RARP_H

using namespace std;
class RARP
{

public:
    string ip;
    string mac;
    map<string,string> *whitelist;
    map<string,string> *blacklist;
    RARP(map<string,string> *whitelist, map<string,string> *blacklist);
    void ricevARP();
};

#endif // RARP_H
