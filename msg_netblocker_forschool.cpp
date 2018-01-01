#include <rarp.h>
#include <blocking.h>
#include <pcap.h>
#include <tins/tins.h>
#include <unistd.h>
#include <whitelisting.h>
#include <logging.h>
#include "msg_netblocker_forschool.h"
#include "ui_msg_netblocker_forschool.h"
#include <thread>

using namespace Tins;
using namespace std;
MSG_NetBlocker_ForSchool::MSG_NetBlocker_ForSchool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MSG_NetBlocker_ForSchool)
{
    ui->setupUi(this);

    ui->ProgramIP->setText(NetworkInterface::default_interface().addresses().ip_addr.to_string().c_str());
    ui->BanIP->setEnabled(false);
    ui->IPScanning->setEnabled(false);
    ui->Logging->setEnabled(false);
}



MSG_NetBlocker_ForSchool::~MSG_NetBlocker_ForSchool()
{
    delete ui;
}




void MSG_NetBlocker_ForSchool::on_Start_clicked()
{
//    ui->WhitelistEdit->setEnabled(false);
//    ui->IPBand1->setEnabled(false);
//    ui->IPBand2->setEnabled(false);
//    ui->GateWayIP->setEnabled(false);
//    ui->ProgramIP->setEnabled(false);
//    ui->LogLocationEdit->setEnabled(false);
//    ui->BanIP->setEnabled(false);
//    ui->IPScanning->setEnabled(false);
//    ui->Logging->setEnabled(false);
//    ui->Start->setEnabled(false);
//    ui->Reset->setEnabled(false);
//    ui->StatusNow->setText("Starting...");

    string myip = ui->ProgramIP->text().toUtf8().data();

    string gatewayip = ui->GateWayIP->text().toUtf8().data();

    string ip1 = ui->IPBand1->text().toUtf8().data();
    string ip2 = ui->IPBand2->text().toUtf8().data();
    string Whitelist = ui->WhitelistEdit->text().toUtf8().data();
    string log = ui->LogLocationEdit->text().toUtf8().data();

    WhiteListing *whitel = new WhiteListing(Whitelist);
    whitel->loadwhitelist();
    whitel->white.insert({myip,NetworkInterface::default_interface().addresses().hw_addr.to_string()});

    Logging *lg  = new Logging(log);

    std::thread rrp_tr(&RARP::ricevARP,RARP(whitel,lg));
    std::thread srp_tr(&SARP::sndBand, SARP(), ip1,ip2);
    std::thread blk_tr(&Blocking::bloc,Blocking(whitel,gatewayip));

    rrp_tr.join();
    srp_tr.join();
    blk_tr.join();








}

void MSG_NetBlocker_ForSchool::on_Stop_clicked()
{
    ui->WhitelistEdit->setEnabled(true);
    ui->IPBand1->setEnabled(true);
    ui->IPBand2->setEnabled(true);
    ui->GateWayIP->setEnabled(true);
    ui->ProgramIP->setEnabled(true);
    ui->LogLocationEdit->setEnabled(true);
    //ui->BanIP->setEnabled(true);
    //ui->IPScanning->setEnabled(true);
    //ui->Logging->setEnabled(true);
    ui->Reset->setEnabled(true);
    ui->Start->setEnabled(true);
    ui->StatusNow->setText("Stopped.");

}


void MSG_NetBlocker_ForSchool::on_Reset_clicked()
{
    ui->WhitelistEdit->setText("");
    ui->IPBand1->setText("");
    ui->IPBand2->setText("");
    ui->GateWayIP->setText("");
    ui->ProgramIP->setText("");
    ui->LogLocationEdit->setText("");
    ui->BanIP->setChecked(true);
    ui->IPScanning->setChecked(true);
    ui->Logging->setChecked(true);
}
