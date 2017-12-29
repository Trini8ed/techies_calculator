#include "Techies_Main.h"
#include "ui_Techies_Main.h"

//Data Structures

struct resistance {
    double mag_res;
    double dmg_red;
};

struct scenerios {
    QString name;
    int hp;
    resistance res;
    int cleared;
};

struct ability_levels {
    int prox_level;
    int blast_off_level;
    int remote_level;
};

Techies_Main::Techies_Main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Techies_Main)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("techies.ico"));

    QString name = "Techies Damage Calculator";
    this->setWindowTitle(name);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    updater();

}

//Global Values
resistance input = {0.25,0.0};
ability_levels levels = {1,1,1};
scenerios s1 = {"",0,0,0,0};
scenerios s2 = {"",0,0,0,0};
scenerios s3 = {"",0,0,0,0};

Techies_Main::~Techies_Main()
{
    delete ui;
}

void Techies_Main::updater()
{
    //Proximity Calculations
    double prox_dmg;
    if (levels.prox_level == 1){
        prox_dmg = 200 * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_1_prox_dmg->setNum(prox_dmg * ui->amt_1->value());
        ui->amt_2_prox_dmg->setNum(prox_dmg * ui->amt_2->value());
        ui->amt_3_prox_dmg->setNum(prox_dmg * ui->amt_3->value());
        ui->amt_4_prox_dmg->setNum(prox_dmg * ui->amt_4->value());
    }
    else if (levels.prox_level == 2){
        prox_dmg = 400 * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_1_prox_dmg->setNum(prox_dmg * ui->amt_1->value());
        ui->amt_2_prox_dmg->setNum(prox_dmg * ui->amt_2->value());
        ui->amt_3_prox_dmg->setNum(prox_dmg * ui->amt_3->value());
        ui->amt_4_prox_dmg->setNum(prox_dmg * ui->amt_4->value());
    }
    else if (levels.prox_level == 3){
        prox_dmg = 600 * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_1_prox_dmg->setNum(prox_dmg * ui->amt_1->value());
        ui->amt_2_prox_dmg->setNum(prox_dmg * ui->amt_2->value());
        ui->amt_3_prox_dmg->setNum(prox_dmg * ui->amt_3->value());
        ui->amt_4_prox_dmg->setNum(prox_dmg * ui->amt_4->value());
    }
    else if (levels.prox_level == 4){
        prox_dmg = 800 * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_1_prox_dmg->setNum(prox_dmg * ui->amt_1->value());
        ui->amt_2_prox_dmg->setNum(prox_dmg * ui->amt_2->value());
        ui->amt_3_prox_dmg->setNum(prox_dmg * ui->amt_3->value());
        ui->amt_4_prox_dmg->setNum(prox_dmg * ui->amt_4->value());
    }

    //Remote Calculations

    double remote_dmg;
    double aghs_check = 0;
    if (ui->aghs_check->isChecked()){
        aghs_check += 150;
    }
    if (levels.remote_level == 1){
        remote_dmg = (300 + aghs_check) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_1_remote_dmg->setNum(remote_dmg * ui->amt_1->value());
        ui->amt_2_remote_dmg->setNum(remote_dmg * ui->amt_2->value());
        ui->amt_3_remote_dmg->setNum(remote_dmg * ui->amt_3->value());
        ui->amt_4_remote_dmg->setNum(remote_dmg * ui->amt_4->value());
    }
    else if (levels.remote_level == 2){
        remote_dmg = (450 + aghs_check) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_1_remote_dmg->setNum(remote_dmg * ui->amt_1->value());
        ui->amt_2_remote_dmg->setNum(remote_dmg * ui->amt_2->value());
        ui->amt_3_remote_dmg->setNum(remote_dmg * ui->amt_3->value());
        ui->amt_4_remote_dmg->setNum(remote_dmg * ui->amt_4->value());
    }
    else if (levels.remote_level == 3){
        remote_dmg = (600 + aghs_check) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_1_remote_dmg->setNum(remote_dmg * ui->amt_1->value());
        ui->amt_2_remote_dmg->setNum(remote_dmg * ui->amt_2->value());
        ui->amt_3_remote_dmg->setNum(remote_dmg * ui->amt_3->value());
        ui->amt_4_remote_dmg->setNum(remote_dmg * ui->amt_4->value());
    }

    //Blast Off Calculations

    double blast_off_dmg;
    int talent_check = 0;
    if (ui->blast_off_check->isChecked()){
        talent_check = 300;
    }
    if (levels.blast_off_level == 1){
        blast_off_dmg = (300 + talent_check) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_blast_off_dmg->setNum(blast_off_dmg);
    }
    else if (levels.blast_off_level == 2){
        blast_off_dmg = (400 + talent_check) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_blast_off_dmg->setNum(blast_off_dmg);
    }
    else if (levels.blast_off_level == 3){
        blast_off_dmg = (500 + talent_check) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_blast_off_dmg->setNum(blast_off_dmg);
    }
    else if (levels.blast_off_level == 4){
        blast_off_dmg = (600 + talent_check) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
        ui->amt_blast_off_dmg->setNum(blast_off_dmg);
    }

    //HP Calculator
    int remote_mines = 1;
    if (!ui->aghs_check->isChecked()){
        if (levels.remote_level == 1){
            for (int i = 1; (remote_mines * 300 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                remote_mines++;
            }
        }
        else if (levels.remote_level == 2){
            for (int i = 1; (remote_mines * 450 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                remote_mines++;
            }
        }
        else if (levels.remote_level == 3){
            for (int i = 1; (remote_mines * 600 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                remote_mines++;
            }
        }
    }
    else if (ui->aghs_check->isChecked()){
        if (levels.remote_level == 1){
            for (int i = 1; (remote_mines * 450 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                remote_mines++;
            }
        }
        else if (levels.remote_level == 2){
            for (int i = 1; (remote_mines * 600 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                remote_mines++;
            }
        }
        else if (levels.remote_level == 3){
            for (int i = 1; (remote_mines * 750 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                remote_mines++;
            }
        }
    }

    ui->hp_remote_qty->setNum(remote_mines);

    //HP Prox Mine
    int prox_mines = 1;
        if (levels.prox_level == 1){
            for (int i = 1; (prox_mines * 200 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                prox_mines++;
            }
        }
        else if (levels.prox_level == 2){
            for (int i = 1; (prox_mines * 400 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                prox_mines++;
            }
        }
        else if (levels.prox_level == 3){
            for (int i = 1; (prox_mines * 600 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                prox_mines++;
            }
        }
        else if (levels.prox_level == 4){
            for (int i = 1; (prox_mines * 800 * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value(); i++){
                prox_mines++;
            }
        }

    ui->hp_prox_qty->setNum(prox_mines);
}

void Techies_Main::on_actionExit_triggered()
{
    exit(0);
}

void Techies_Main::on_aghs_check_clicked()
{
    if (ui->aghs_check->isChecked()){
        QPixmap aghs("images/aghs.png");
        ui->aghs_check_img->setPixmap(aghs);
    }
    else if (!ui->aghs_check->isChecked()){
        QPixmap no_aghs("images/no_aghs.png");
        ui->aghs_check_img->setPixmap(no_aghs);
    }
    updater();
}

void Techies_Main::on_blast_off_check_clicked()
{
    if (ui->blast_off_check->isChecked()){
        QPixmap talent("images/leveled_talent.png");
        ui->blast_off_check_img->setPixmap(talent);
    }
    else if (!ui->blast_off_check->isChecked()){
        QPixmap no_talent("images/unleveled_talent.png");
        ui->blast_off_check_img->setPixmap(no_talent);
    }
    updater();
}

void Techies_Main::on_prox_level_up_clicked()
{
    QPixmap level("images/leveled.png");
    QPixmap unleveled("images/unleveled.png");

    if (levels.prox_level == 1){
        ui->prox_level_2_img->setPixmap(level);
        levels.prox_level++;
    }
    else if (levels.prox_level == 2){
        ui->prox_level_3_img->setPixmap(level);
        levels.prox_level++;
    }
    else if (levels.prox_level == 3){
        ui->prox_level_4_img->setPixmap(level);
        levels.prox_level++;
    }
    else if (levels.prox_level == 4){
        ui->prox_level_2_img->setPixmap(unleveled);
        ui->prox_level_3_img->setPixmap(unleveled);
        ui->prox_level_4_img->setPixmap(unleveled);
        levels.prox_level = 1;
    }
    specific_update();
    updater();
}

void Techies_Main::on_blast_off_level_up_clicked()
{
    QPixmap level("images/leveled.png");
    QPixmap unleveled("images/unleveled.png");

    if (levels.blast_off_level == 1){
        ui->blast_off_level_2_img->setPixmap(level);
        levels.blast_off_level++;

    }
    else if (levels.blast_off_level == 2){
        ui->blast_off_level_3_img->setPixmap(level);
        levels.blast_off_level++;

    }
    else if (levels.blast_off_level == 3){
        ui->blast_off_level_4_img->setPixmap(level);
        levels.blast_off_level++;

    }
    else if (levels.blast_off_level == 4){
        ui->blast_off_level_2_img->setPixmap(unleveled);
        ui->blast_off_level_3_img->setPixmap(unleveled);
        ui->blast_off_level_4_img->setPixmap(unleveled);
        levels.blast_off_level = 1;

    }
    updater();
}

void Techies_Main::on_remote_level_up_clicked()
{
    QPixmap level("images/leveled.png");
    QPixmap unleveled("images/unleveled.png");

    if (levels.remote_level == 1){
        ui->remote_level_2_img->setPixmap(level);
        levels.remote_level++;
    }
    else if (levels.remote_level == 2){
        ui->remote_level_3_img->setPixmap(level);
        levels.remote_level++;
    }
    else if (levels.remote_level == 3){
        ui->remote_level_2_img->setPixmap(unleveled);
        ui->remote_level_3_img->setPixmap(unleveled);
        levels.remote_level = 1;
    }
    specific_update();
    updater();
}

void Techies_Main::on_magic_res_valueChanged(double arg1)
{
    input.mag_res = (arg1 / 100.00);
    updater();
}

void Techies_Main::on_dmg_red_valueChanged(double arg1)
{
    if(ui->dmg_red_check->isChecked()){
        input.dmg_red = (arg1 / 100.00);
    }
    else if(!ui->dmg_red_check->isChecked()){
        input.dmg_red = 0.00;
    }
    updater();
}

void Techies_Main::on_dmg_red_check_clicked()
{
    QPixmap dmg_red_on("images/dmg_reduction.png");
    QPixmap dmg_red_off("images/dmg_reduction_off.png");
    if(ui->dmg_red_check->isChecked()){
        input.dmg_red = (ui->dmg_red->value()) / 100.00;
        ui->dmg_red_img->setPixmap(dmg_red_on);
        ui->dmg_red_img->setFrameShadow(QFrame::Raised);
    }
    else if(!ui->dmg_red_check->isChecked()){
        input.dmg_red = 0.00;
        ui->dmg_red_img->setPixmap(dmg_red_off);
        ui->dmg_red_img->setFrameShadow(QFrame::Sunken);
    }
    updater();
}

void Techies_Main::on_amt_1_valueChanged()
{
    updater();
}

void Techies_Main::on_amt_2_valueChanged()
{
    updater();
}

void Techies_Main::on_amt_3_valueChanged()
{
    updater();
}

void Techies_Main::on_amt_4_valueChanged()
{
    updater();
}

void Techies_Main::on_hp_value_valueChanged()
{
    updater();
}

void Techies_Main::on_save_clicked()
{
    QPixmap prox("images/proximity.png");
    QPixmap remote("images/remote.png");



    if(ui->save_profile->currentIndex() == 0){
        ui->s1_text->setText(ui->user_profile_name->text());
        ui->s1_prox_qty->setText(ui->hp_prox_qty->text());
        ui->s1_remote_qty->setText(ui->hp_remote_qty->text());
        ui->s1_prox_text->setText("Proximity Mines To Kill: ");
        ui->s1_remote_text->setText("Remote Mines To Kill: ");

        ui->s1_prox_img->setPixmap(prox);
        ui->s1_remote_img->setPixmap(remote);
        ui->save_profile->setItemText(0,ui->user_profile_name->text());
        s1.cleared = 0;
    }
    else if(ui->save_profile->currentIndex() == 1){
        ui->s2_text->setText(ui->user_profile_name->text());
        ui->s2_prox_qty->setText(ui->hp_prox_qty->text());
        ui->s2_remote_qty->setText(ui->hp_remote_qty->text());
        ui->s2_prox_text->setText("Proximity Mines To Kill: ");
        ui->s2_remote_text->setText("Remote Mines To Kill: ");

        ui->s2_prox_img->setPixmap(prox);
        ui->s2_remote_img->setPixmap(remote);
        ui->save_profile->setItemText(1,ui->user_profile_name->text());
        s2.cleared = 0;
    }
    else if(ui->save_profile->currentIndex() == 2){
        ui->s3_text->setText(ui->user_profile_name->text());
        ui->s3_prox_qty->setText(ui->hp_prox_qty->text());
        ui->s3_remote_qty->setText(ui->hp_remote_qty->text());
        ui->s3_prox_text->setText("Proximity Mines To Kill: ");
        ui->s3_remote_text->setText("Remote Mines To Kill: ");

        ui->s3_prox_img->setPixmap(prox);
        ui->s3_remote_img->setPixmap(remote);
        ui->save_profile->setItemText(2,ui->user_profile_name->text());
        s3.cleared = 0;
    }
}

void Techies_Main::on_clear_clicked()
{
    if(ui->save_profile->currentIndex() == 0){
        ui->s1_text->setText("Profile 1");
        ui->s1_prox_qty->setText("");
        ui->s1_remote_qty->setText("");
        ui->s1_prox_text->setText("");
        ui->s1_remote_text->setText("");

        ui->s1_prox_img->clear();
        ui->s1_remote_img->clear();
        ui->save_profile->setItemText(0,"Profile 1");
    }
    else if(ui->save_profile->currentIndex() == 1){
        ui->s2_text->setText("Profile 2");
        ui->s2_prox_qty->setText("");
        ui->s2_remote_qty->setText("");
        ui->s2_prox_text->setText("");
        ui->s2_remote_text->setText("");

        ui->s2_prox_img->clear();
        ui->s2_remote_img->clear();
        ui->save_profile->setItemText(1,"Profile 2");
    }
    else if(ui->save_profile->currentIndex() == 2){
        ui->s3_text->setText("Profile 3");
        ui->s3_prox_qty->setText("");
        ui->s3_remote_qty->setText("");
        ui->s3_prox_text->setText("");
        ui->s3_remote_text->setText("");

        ui->s3_prox_img->clear();
        ui->s3_remote_img->clear();
        ui->save_profile->setItemText(2,"Profile 3");
    }
}

void Techies_Main::on_actionAbout_triggered()
{
    About about;
    about.setModal(true);
    about.exec();
}

void Techies_Main::specific_update()
{
    if (s1.cleared == 0){
        ui->s1_prox_qty->setText(ui->hp_prox_qty->text());
        ui->s1_remote_qty->setText(ui->hp_remote_qty->text());
    }

    else if (s2.cleared == 0){
        ui->s2_prox_qty->setText(ui->hp_prox_qty->text());
        ui->s2_remote_qty->setText(ui->hp_remote_qty->text());
    }

    else if (s3.cleared == 0){
        ui->s3_prox_qty->setText(ui->hp_prox_qty->text());
        ui->s3_remote_qty->setText(ui->hp_remote_qty->text());
    }
}
