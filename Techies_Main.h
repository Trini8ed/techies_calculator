#ifndef TECHIES_MAIN_H
#define TECHIES_MAIN_H

#include <iostream>
#include <QMainWindow>
#include <QDialog>
#include "About.h"

namespace Ui {
class Techies_Main;
}

class Techies_Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Techies_Main(QWidget *parent = 0);
    ~Techies_Main();

private slots:
    void specific_update();

    void updater();

    void on_actionExit_triggered();

    void on_aghs_check_clicked();

    void on_blast_off_check_clicked();

    void on_prox_level_up_clicked();

    void on_blast_off_level_up_clicked();

    void on_remote_level_up_clicked();

    void on_magic_res_valueChanged(double arg1);

    void on_dmg_red_valueChanged(double arg1);

    void on_dmg_red_check_clicked();

    void on_amt_1_valueChanged();

    void on_amt_2_valueChanged();

    void on_amt_3_valueChanged();

    void on_amt_4_valueChanged();

    void on_hp_value_valueChanged();

    void on_save_clicked();

    void on_clear_clicked();

    void on_actionAbout_triggered();

private:
    Ui::Techies_Main *ui;
};

#endif // TECHIES_MAIN_H
