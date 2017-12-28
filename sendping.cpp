#include "sendping.h"
#include "tins/tins.h"
using namespace Tins;
SendPing::SendPing()
{

}

int SendPing::SendPing(String target){
   PacketSender send;
   IPv4Address Targetip = IPv4Address(target);
   NetworkInterface interface = NetworkInterface::default_interface();



   EthernetII eth1 = EthernetII("FF:FF:FF:FF:FF:FF",interface.hw_address());
   IP ip = IP(Targetip,interface.addresses());
   ip.protocol(IP::ICMP);

   ICMP sndping = ICMP();
   sndping.code(ICMP::ECHO_REQUEST);

   ip.inner_pdu(sndping);
   eth1.inner_pdu(ip);

   send(eth1,interface);

   return 0;
}

