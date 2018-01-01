#include "whitelisting.h"
#include <iostream>
#include <logging.h>
using namespace std;
WhiteListing::WhiteListing(string filepath)
{
    this->filepath = filepath;
}


void WhiteListing::matching(string ip, string mac, Logging * lg){

    auto witer = white.find(ip);
    auto biter = black.find(ip);
    if(witer==white.end()&&biter==black.end()){
        string logcod = "[illegal ip] ip="+ip+" mac="+mac;
        lg->insertlog(logcod);
        black.insert({ip,mac});
        cout<<"[illegal ip] : ip="<<ip<<" mac="<<mac<<endl;
    }else if(witer!=white.end()&&biter==black.end()){
        if(!witer->second.compare(mac)){
            string logcod = "[illegal mac] ip="+ip+" mac="+mac;
            lg->insertlog(logcod);
             black.insert({ip,mac});
            cout<<"[illegal mac] : ip="<<ip<<" mac="<<mac<<endl;
        }
    }
}

void WhiteListing::loadwhitelist(){
    FILE * fp;
    char str[128];

    fp = fopen(filepath.c_str(),"r");
    while((fgets(str,128,fp))!=NULL){
        printf("[WTincert] %s",str);
        string strt = str;
        string slp = "@";
        string ip = strt.substr(0,strt.find(slp));
        strt.erase(0, strt.find(slp) + slp.length());
        string mac = strt;
        white.insert({ip,mac});
    }
    fclose(fp);

}

