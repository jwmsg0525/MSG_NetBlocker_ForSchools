#include "rarp.h"
#include "logging.h"
#include <tins/tins.h>
#include<functional>
#include <iostream>
using std::bind;
using namespace Tins;
RARP::RARP(WhiteListing * wit , Logging * lg)
{
    this->wit = wit;
    this->lg = lg;
    NetworkInterface interface = NetworkInterface::default_interface();
    SnifferConfiguration config;
    config.set_filter("arp");
    this->snif  = Sniffer(interface.name(),config);

}

bool RARP::ARP_Call_Back(const PDU& pdu){
    const ARP &arp = pdu.rfind_pdu<ARP>();

    if(arp.opcode() == ARP::REPLY){
        wit->matching(arp.sender_ip_addr().to_string(),arp.sender_hw_addr().to_string(),lg);

    }else if(arp.opcode() == ARP::REQUEST){
    }else{

    }

   return true;
}

void RARP::ricevARP(){
    snif.sniff_loop(
            bind(
                &RARP::ARP_Call_Back,
                this,
                std::placeholders::_1
            )
        );
}




