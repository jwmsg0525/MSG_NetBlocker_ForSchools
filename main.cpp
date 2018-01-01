#include "msg_netblocker_forschool.h"
#include <QApplication>
#include <pingmatch.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MSG_NetBlocker_ForSchool w;
    w.show();
    PingMatch pm = PingMatch();
    pm.sniff();
    return a.exec();
}
