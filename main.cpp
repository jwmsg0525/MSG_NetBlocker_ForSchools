#include "msg_netblocker_forschool.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MSG_NetBlocker_ForSchool w;
    w.show();

    return a.exec();
}
