#ifndef HV_H
#define HV_H

#include <QWidget>
#include <QTimer>
#include "hvmodule.h"

namespace Ui {
class hv;
}

class hv : public QWidget
{
    Q_OBJECT

public:
    explicit hv(QWidget *parent = 0, int handleChef_ = 0);
    void pauseTimer();
    void restartTimer();
    ~hv();

private slots:
    void on_spinBox_hv_rotary_switches_valueChanged(int rotSw);
    void updateUI();

    void on_pushButton_hv_set_clicked();

    void on_radioButton_hv_on_off_clicked();

private:
    // user interface
    Ui::hv *ui;

    // instance of corresponding module
    HVModule *module;

    // utils
    void makeItNice();
    void launchTimer(int interval);


    // methods
    void updateBaseAddress(int rotSw);
    void updateVMAX();
    void updateIMAX();
    void updateHV();

    // members
    QTimer* timer;
    int interval;



};

#endif // HV_H
