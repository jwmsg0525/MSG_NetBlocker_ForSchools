#include <iostream>
#include <map>
#include <logging.h>
#include <stdio.h>
#ifndef WHITELISTING_H
#define WHITELISTING_H

using namespace std;

class WhiteListing
{
public:
    map<string,string> white;
    map<string,string> black;
    string filepath;
    WhiteListing(string filepath);
    void loadwhitelist();
    void matching(string ip, string mac, Logging *lg);
};

#endif // WHITELISTING_H
