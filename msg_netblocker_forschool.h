#ifndef MSG_NETBLOCKER_FORSCHOOL_H
#define MSG_NETBLOCKER_FORSCHOOL_H

#include <QMainWindow>

namespace Ui {
class MSG_NetBlocker_ForSchool;
}

class MSG_NetBlocker_ForSchool : public QMainWindow
{
    Q_OBJECT

public:
    explicit MSG_NetBlocker_ForSchool(QWidget *parent = 0);
    ~MSG_NetBlocker_ForSchool();

private slots:
    void on_Start_clicked();

    void on_Stop_clicked();

    void on_Reset_clicked();

private:
    Ui::MSG_NetBlocker_ForSchool *ui;
};

#endif // MSG_NETBLOCKER_FORSCHOOL_H
