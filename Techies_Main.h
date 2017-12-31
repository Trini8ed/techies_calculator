#ifndef TECHIES_MAIN_H
#define TECHIES_MAIN_H

#include <iostream>
#include <QMainWindow>
#include <QDialog>
#include "About.h"
#include "Magic_Res.h"

namespace Ui {
class Techies_Main;
}

class Techies_Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Techies_Main(QWidget *parent = 0);
    ~Techies_Main();
    friend void Magic_Res::do_magic();
	
private slots:
    void magic_res(double arg1);

    void scenerio_updater();

    void updater();

    void hp_update();

    void prox_level();

    void remote_update();

    void suicide_update();

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

    void on_actionDota_2_triggered();

    void on_disable_clicked();

    void on_s1_hp_value_valueChanged(int arg1);

    void on_s1_mag_res_box_valueChanged(double arg1);

    void on_s1_dmg_red_box_valueChanged(double arg1);

    void on_s2_hp_value_valueChanged(int arg1);

    void on_s2_mag_res_box_valueChanged(double arg1);

    void on_s2_dmg_red_box_valueChanged(double arg1);

    void on_s3_hp_value_valueChanged(int arg1);

    void on_s3_mag_res_box_valueChanged(double arg1);

    void on_s3_dmg_red_box_valueChanged(double arg1);

    void s1_qty_calc();

    void s2_qty_calc();

    void s3_qty_calc();

    void on_magic_popout_clicked();

private:
    Ui::Techies_Main *ui;
};

#endif // TECHIES_MAIN_H
