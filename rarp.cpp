#include "rarp.h"

RARP::RARP(map<string,string> *whitelist, map<string,string> *blacklist)
{
    this->whitelist = whitelist;
    this->blacklist = blacklist;
}

bool ARP_Call_Back(const PDU& pdu){

}

void RARP::ricevARP(){

}
