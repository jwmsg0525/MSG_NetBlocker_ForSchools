#include <iostream>
#include <stdio.h>
#ifndef LOGGING_H
#define LOGGING_H
using namespace std;

class Logging
{
public:
    string filepath;
    Logging(string filepath);
    void insertlog(string data);
};

#endif // LOGGING_H
