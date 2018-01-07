#ifndef TECHIES_MAIN_H
#define TECHIES_MAIN_H

#include <iostream>

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QFile>
#include <QScreen>
#include <QWindow>
#include "Screen_Data.h"
#include "About.h"
#include "Magic_Res.h"
#include "Dmg_Red.h"

namespace Ui {
class Techies_Main;
}

class Techies_Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Techies_Main(QWidget *parent = 0);
    ~Techies_Main();

    void QPixMap_Data(QPixmap game);

private slots:

    void updater();

    void scenerio_updater();

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

    void on_magic_res_valueChanged(double arg1);

    void magic_res(double arg1);

    void dmg_red(double arg1);

    void onMessageSentMag(const double &);

    void onMessageSentDmg(const double &);

    void on_dmg_red_popout_clicked();

    void on_screenshot_clicked();

private:
    Ui::Techies_Main *ui;
    Magic_Res* _mag;
    Dmg_Red* _dmg;

};

#endif // TECHIES_MAIN_H
