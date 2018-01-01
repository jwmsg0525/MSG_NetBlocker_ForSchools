#include "blocking.h"

Blocking::Blocking(WhiteListing * wit, string gatewayip)
{
    this->wit = wit;
    this->gatewayip = gatewayip;
}

void Blocking::bloc(){
    SARP srp;
    while(true){
    string mymac = NetworkInterface::default_interface().addresses().hw_addr.to_string();
    for(auto iter = wit->black.begin() ; iter != wit->black.end();iter++){
        if((iter->first).compare(gatewayip) && (iter->second).compare(mymac)){
        srp.sendRS(iter->first,gatewayip,iter->second,NetworkInterface::default_interface().addresses().hw_addr.to_string());
        }
    }
    }
}

