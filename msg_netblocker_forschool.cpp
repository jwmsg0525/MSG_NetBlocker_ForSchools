#include "msg_netblocker_forschool.h"
#include "ui_msg_netblocker_forschool.h"

MSG_NetBlocker_ForSchool::MSG_NetBlocker_ForSchool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MSG_NetBlocker_ForSchool)
{
    ui->setupUi(this);

}



MSG_NetBlocker_ForSchool::~MSG_NetBlocker_ForSchool()
{
    delete ui;
}

void MSG_NetBlocker_ForSchool::on_Start_clicked()
{
    ui->WhitelistEdit->setEnabled(false);
    ui->IPBand1->setEnabled(false);
    ui->IPBand2->setEnabled(false);
    ui->GateWayIP->setEnabled(false);
    ui->ProgramIP->setEnabled(false);
    ui->LogLocationEdit->setEnabled(false);
    ui->BanIP->setEnabled(false);
    ui->IPScanning->setEnabled(false);
    ui->Logging->setEnabled(false);
    ui->Reset->setEnabled(false);
    ui->StatusNow->setText("Starting...");


}

void MSG_NetBlocker_ForSchool::on_Stop_clicked()
{
    ui->WhitelistEdit->setEnabled(true);
    ui->IPBand1->setEnabled(true);
    ui->IPBand2->setEnabled(true);
    ui->GateWayIP->setEnabled(true);
    ui->ProgramIP->setEnabled(true);
    ui->LogLocationEdit->setEnabled(true);
    ui->BanIP->setEnabled(true);
    ui->IPScanning->setEnabled(true);
    ui->Logging->setEnabled(true);
    ui->Reset->setEnabled(true);
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
