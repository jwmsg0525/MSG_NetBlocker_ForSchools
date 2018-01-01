#include "sarp.h"
#include "rarp.h"

#include "tins/tins.h"
#include <string.h>

using namespace Tins;
using namespace std;
SARP::SARP()
{

}

void SARP::sendRQ(string dstip){
    NetworkInterface interface = NetworkInterface::default_interface();
    auto addrs = interface.addresses();
    EthernetII eth = ARP::make_arp_request(dstip,addrs.ip_addr,addrs.hw_addr);
    PacketSender sender;
    sender.send(eth,interface.name());

}

void SARP::sendRS(string dstip,string srcip, string dstmac, string srcmac){
    NetworkInterface interface = NetworkInterface::default_interface();
    EthernetII eth = ARP::make_arp_reply(dstip,srcip,dstmac,srcmac);

    PacketSender sender;
    sender.send(eth,interface.name());
}

void SARP::sndBand(string startbnd , string endband){
string spl = ".";
string strt = startbnd;
string endt = endband;
string s1 = strt.substr(0,strt.find(spl));
strt.erase(0, strt.find(spl) + spl.length());
string s2 = strt.substr(0,strt.find(spl));
strt.erase(0, strt.find(spl) + spl.length());
string s3 = strt.substr(0,strt.find(spl));
strt.erase(0, strt.find(spl) + spl.length());
string s4 = strt;

string e1 = endt.substr(0,endt.find(spl));
endt.erase(0, endt.find(spl) + spl.length());
string e2 = endt.substr(0,endt.find(spl));
endt.erase(0, endt.find(spl) + spl.length());
string e3 = endt.substr(0,endt.find(spl));
endt.erase(0, endt.find(spl) + spl.length());
string e4 = endt;

int si1 = stoi(s1);
int si2 = stoi(s2);
int si3 = stoi(s3);
int si4 = stoi(s4);

int ei1 = stoi(e1);
int ei2 = stoi(e2);
int ei3 = stoi(e3);
int ei4 = stoi(e4);

int a1,a2,a3,a4;
while(true){
for(a1=si1;a1<=ei1;a1++){
    for(a2=si2;a2<=ei2;a2++){
        for(a3 = si3; a3<=ei3;a3++){
            for(a4=si4;a4<=ei4;a4++){

                string ip = to_string(a1)+"."+to_string(a2)+"."+to_string(a3)+"."+to_string(a4);
                //cout<<ip<<endl;
                sendRQ(ip);

            }
        }
    }
}
}





}
