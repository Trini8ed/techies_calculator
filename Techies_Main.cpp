#include "Techies_Main.h"
#include "ui_Techies_Main.h"

//_______________
//Data Structures
//_______________

struct resistance {
    double mag_res;
    double dmg_red;
};

struct scenerios {
    QString name;
    int hp;
    resistance res;
    int prox_qty;
    int remote_qty;
    int cleared;
};

struct ability_levels_data {
    int prox_level[4];
    int blast_off_level[4];
    int talent_blast_off_level[4];
    int remote_level[3];
    int aghs_remote_level[3];
};

struct ability_levels {
    int prox_level;
    int blast_off_level;
    int remote_level;
};

//_____________
//Global Values
//_____________

const ability_levels_data levels_data = {
        //Prox Mines 1-4
        {200, 400, 600, 800},
        //Blast off 1-4
        {300, 400, 500, 600},
        //Blast off with talent 1-4
        {600, 700, 800, 900},
        //Remote mines 1-4
        {300, 450, 600},
        //Remote mines with aghs 1-4
        {450, 600, 750}
};

const scenerios cleared = {"Profile", 1000,.25,0,0,0,1};
resistance input;
ability_levels levels;
scenerios s1;
scenerios s2;
scenerios s3;

Techies_Main::Techies_Main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Techies_Main)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("techies.ico"));

    QString name = "Techies Damage Calculator";
    this->setWindowTitle(name);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    //Update Profile Data

    s1.name = ui->s1_text->text();
    s1.hp = ui->s1_hp_value->value();
    s1.res.mag_res = ui->s1_mag_res_box->value()/100.0;
    s1.res.dmg_red = ui->s1_dmg_red_box->value()/100.0;
    s1.prox_qty = ui->s1_remote_qty->text().toInt();
    s1.remote_qty = ui->s1_prox_qty->text().toInt();
    s1.cleared = 0;

    s2.name = ui->s2_text->text();
    s2.hp = ui->s2_hp_value->value();
    s2.res.mag_res = ui->s2_mag_res_box->value()/100.0;
    s2.res.dmg_red = ui->s2_dmg_red_box->value()/100.0;
    s2.prox_qty = ui->s2_remote_qty->text().toInt();
    s2.remote_qty = ui->s2_prox_qty->text().toInt();
    s2.cleared = 0;

    s3.name = ui->s3_text->text();
    s3.hp = ui->s3_hp_value->value();
    s3.res.mag_res = ui->s3_mag_res_box->value()/100.0;
    s3.res.dmg_red = ui->s3_dmg_red_box->value()/100.0;
    s3.prox_qty = ui->s3_remote_qty->text().toInt();
    s3.remote_qty = ui->s3_prox_qty->text().toInt();
    s3.cleared = 0;

    input.dmg_red = 0.0;
    input.mag_res = ui->magic_res->value()/100.0;

    levels.prox_level = 1;
    levels.blast_off_level = 1;
    levels.remote_level = 1;

    s1_qty_calc();
    s2_qty_calc();
    s3_qty_calc();
    updater();
}

Techies_Main::~Techies_Main()
{
    delete ui;
}

void Techies_Main::hp_update()
{
    //HP Calculator
    int remote_mines_dmg = levels_data.remote_level[levels.remote_level - 1];
    if (ui->aghs_check->isChecked()){
        remote_mines_dmg = levels_data.aghs_remote_level[levels.remote_level - 1];
    }
    int remote_mines_qty = 1;
    while ((remote_mines_qty * remote_mines_dmg * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value()){
        remote_mines_qty++;
    }

    ui->hp_remote_qty->setNum(remote_mines_qty);

    int prox_mines_dmg = levels_data.prox_level[levels.prox_level - 1];
    int prox_mines_qty = 1;
    while ((prox_mines_qty * prox_mines_dmg * (1.0 - input.dmg_red) * (1.0 - input.mag_res)) < ui->hp_value->value()){
        prox_mines_qty++;
    }

    ui->hp_prox_qty->setNum(prox_mines_qty);
}

void Techies_Main::prox_level()
{
    int prox_dmg_output = levels_data.prox_level[levels.prox_level-1] * (1.0 - input.dmg_red) * (1.0 - input.mag_res);

    //Update Table Data
    ui->amt_1_prox_dmg->setNum(prox_dmg_output * ui->amt_1->value());
    ui->amt_2_prox_dmg->setNum(prox_dmg_output * ui->amt_2->value());
    ui->amt_3_prox_dmg->setNum(prox_dmg_output * ui->amt_3->value());
    ui->amt_4_prox_dmg->setNum(prox_dmg_output * ui->amt_4->value());
}

void Techies_Main::remote_update()
{
    int remote_level_dmg = levels_data.remote_level[levels.remote_level-1];
    if (ui->aghs_check->isChecked()){
        remote_level_dmg = levels_data.aghs_remote_level[levels.remote_level-1];
    }
    int remote_dmg_output = (remote_level_dmg) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);

    //Update Table Data
    ui->amt_1_remote_dmg->setNum(remote_dmg_output * ui->amt_1->value());
    ui->amt_2_remote_dmg->setNum(remote_dmg_output * ui->amt_2->value());
    ui->amt_3_remote_dmg->setNum(remote_dmg_output * ui->amt_3->value());
    ui->amt_4_remote_dmg->setNum(remote_dmg_output * ui->amt_4->value());
}

void Techies_Main::suicide_update()
{
    int blast_off_level_dmg = levels_data.blast_off_level[levels.blast_off_level - 1];
    if (ui->blast_off_check->isChecked()){
        blast_off_level_dmg = levels_data.talent_blast_off_level[levels.blast_off_level - 1];
    }
    int blast_off_dmg_output = (blast_off_level_dmg) * (1.0 - input.dmg_red) * (1.0 - input.mag_res);
    ui->amt_blast_off_dmg->setNum(blast_off_dmg_output);
}

void Techies_Main::updater()
{
    suicide_update();
    remote_update();
    prox_level();
    hp_update();
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
    s1_qty_calc();
    s2_qty_calc();
    s3_qty_calc();
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
    updater();
    s1_qty_calc();
    s2_qty_calc();
    s3_qty_calc();
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
    scenerio_updater();
    updater();
    s1_qty_calc();
    s2_qty_calc();
    s3_qty_calc();
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

    if(ui->save_profile->currentIndex() == 0){
        s1.name = ui->user_profile_name->text();
        s1.hp = ui->hp_value->value();
        s1.res.mag_res = ui->magic_res->value()/100.0;
        s1.prox_qty = ui->hp_prox_qty->text().toInt();
        s1.remote_qty = ui->hp_remote_qty->text().toInt();
        s1.cleared = 0;

        //Disable Click Area
        ui->frame_1->setEnabled(true);

        //Damage Reduction
        if (ui->dmg_red_check->isChecked()){
                s1.res.dmg_red = ui->dmg_red->value()/100.0;
        }
        else s1.res.dmg_red = 0.0;

        //Change Combo Box Name
        ui->save_profile->setItemText(0,s1.name);
        scenerio_updater();
    }
    else if(ui->save_profile->currentIndex() == 1){
        s2.name = ui->user_profile_name->text();
        s2.hp = ui->hp_value->value();
        s2.res.mag_res = ui->magic_res->value()/100.0;
        s2.prox_qty = ui->hp_prox_qty->text().toInt();
        s2.remote_qty = ui->hp_remote_qty->text().toInt();
        s2.cleared = 0;


        //Disable Click Area
        ui->frame_2->setEnabled(true);

        //Damage Reduction
        if (ui->dmg_red_check->isChecked()){
                s2.res.dmg_red = ui->dmg_red->value()/100.0;
        }

        else s2.res.dmg_red = 0.0;


        //Change Combo Box Name
        ui->save_profile->setItemText(1,s2.name);
        scenerio_updater();
    }
    else if(ui->save_profile->currentIndex() == 2){
        s3.name = ui->user_profile_name->text();
        s3.hp = ui->hp_value->value();
        s3.res.mag_res = ui->magic_res->value()/100.0;
        s3.prox_qty = ui->hp_prox_qty->text().toInt();
        s3.remote_qty = ui->hp_remote_qty->text().toInt();
        s3.cleared = 0;

        //Disable Click Area
        ui->frame_3->setEnabled(true);

        //Damage Reduction
        if (ui->dmg_red_check->isChecked()){
                s3.res.dmg_red = ui->dmg_red->value()/100.0;
        }

        else s3.res.dmg_red = 0.0;

        //Change Combo Box Name
        ui->save_profile->setItemText(2,s3.name);
        scenerio_updater();
    }
}

void Techies_Main::on_clear_clicked()
{
    if (ui->frame_scenerios->isHidden()){
        ui->frame_scenerios->show();
        Techies_Main::setMinimumHeight(720);
        Techies_Main::setMinimumWidth(824);
        Techies_Main::setMaximumHeight(720);
        Techies_Main::setMaximumWidth(824);
    }
    else if (!ui->frame_scenerios->isHidden()){
        ui->frame_scenerios->hide();
        Techies_Main::setMinimumHeight(481);
        Techies_Main::setMinimumWidth(791);
        Techies_Main::setMaximumHeight(481);
        Techies_Main::setMaximumWidth(791);
    }
}

void Techies_Main::on_actionAbout_triggered()
{
    About about;
    about.setModal(true);
    about.exec();
}

void Techies_Main::scenerio_updater()
{
    if (s1.cleared == 0){
        ui->s1_mag_res_box->setValue(s1.res.mag_res*100.0);
        ui->s1_dmg_red_box->setValue(s1.res.dmg_red*100.0);
        ui->s1_hp_value->setValue(s1.hp);
        ui->s1_text->setText(s1.name);
        ui->s1_prox_qty->setText(QString::number(s1.prox_qty));
        ui->s1_remote_qty->setText(QString::number(s1.remote_qty));
    }
    if (s2.cleared == 0){
        ui->s2_mag_res_box->setValue(s2.res.mag_res*100.0);
        ui->s2_dmg_red_box->setValue(s2.res.dmg_red*100.0);
        ui->s2_hp_value->setValue(s2.hp);
        ui->s2_text->setText(s2.name);
        ui->s2_prox_qty->setText(QVariant(s2.prox_qty).toString());
        ui->s2_remote_qty->setText(QVariant(s2.remote_qty).toString());
    }
    if (s3.cleared == 0){
        ui->s3_mag_res_box->setValue(s3.res.mag_res*100.0);
        ui->s3_dmg_red_box->setValue(s3.res.dmg_red*100.0);
        ui->s3_hp_value->setValue(s3.hp);
        ui->s3_text->setText(s3.name);
        ui->s3_prox_qty->setText(QVariant(s3.prox_qty).toString());
        ui->s3_remote_qty->setText(QVariant(s3.remote_qty).toString());
    }
}

void Techies_Main::on_actionDota_2_triggered()
{
    exit(0);
}

void Techies_Main::on_disable_clicked()
{
    if(ui->save_profile->currentIndex() == 0){
        s1 = cleared;
        s1.name = cleared.name + " " + QVariant(1).toString();

        ui->s1_text->setText(s1.name);
        ui->s1_prox_qty->setText(QVariant(s1.prox_qty).toString());
        ui->s1_remote_qty->setText(QVariant(s1.remote_qty).toString());
        ui->s1_hp_value->setValue(s1.hp);
        ui->s1_mag_res_box->setValue(s1.res.mag_res*100.0);
        ui->s1_dmg_red_box->setValue(s1.res.dmg_red*100.0);

        //Disable Click Area
        ui->frame_1->setEnabled(false);

        //Change Combo Box Name
        ui->save_profile->setItemText(0,cleared.name + " " + QVariant(1).toString());
    }
    else if(ui->save_profile->currentIndex() == 1){
        s2 = cleared;
        s2.name = cleared.name + " " + QVariant(2).toString();

        ui->s2_text->setText(s2.name);
        ui->s2_prox_qty->setText(QVariant(s2.prox_qty).toString());
        ui->s2_remote_qty->setText(QVariant(s2.remote_qty).toString());
        ui->s2_hp_value->setValue(s2.hp);
        ui->s2_mag_res_box->setValue(s2.res.mag_res*100.0);
        ui->s2_dmg_red_box->setValue(s2.res.dmg_red*100.0);

        //Disable Click Area
        ui->frame_2->setEnabled(false);

        //Change Combo Box Name
        ui->save_profile->setItemText(1,cleared.name + " " + QVariant(2).toString());
    }
    else if(ui->save_profile->currentIndex() == 2){
        s3 = cleared;
        s3.name = cleared.name + " " + QVariant(3).toString();

        ui->s3_text->setText(s3.name);
        ui->s3_prox_qty->setText(QVariant(s3.prox_qty).toString());
        ui->s3_remote_qty->setText(QVariant(s3.remote_qty).toString());
        ui->s3_hp_value->setValue(s3.hp);
        ui->s3_mag_res_box->setValue(s3.res.mag_res*100.0);
        ui->s3_dmg_red_box->setValue(s3.res.dmg_red*100.0);

        //Disable Click Area
        ui->frame_3->setEnabled(false);

        //Change Combo Box Name
        ui->save_profile->setItemText(2,cleared.name + " " + QVariant(3).toString());
    }
}

void Techies_Main::s1_qty_calc()
{
    int remote_mines_dmg = levels_data.remote_level[levels.remote_level - 1];
    if (ui->aghs_check->isChecked()){
        remote_mines_dmg = levels_data.aghs_remote_level[levels.remote_level - 1];
    }
    int remote_mines_qty = 1;
    while ((remote_mines_qty * remote_mines_dmg * (1.0 - s1.res.dmg_red) * (1.0 - s1.res.mag_res)) < s1.hp){
        remote_mines_qty++;
    }

    int prox_mines_dmg = levels_data.prox_level[levels.prox_level - 1];
    int prox_mines_qty = 1;
    while ((prox_mines_qty * prox_mines_dmg * (1.0 - s1.res.dmg_red) * (1.0 - s1.res.mag_res)) < s1.hp){
        prox_mines_qty++;
    }

    if (s1.cleared == 1){
        ui->s1_prox_qty->setText("0");
        ui->s1_remote_qty->setText("0");
    }

    else {
    s1.prox_qty = prox_mines_qty;
    ui->s1_prox_qty->setText(QVariant(s1.prox_qty).toString());
    s1.remote_qty = remote_mines_qty;
    ui->s1_remote_qty->setText(QVariant(s1.remote_qty).toString());
    }
}

void Techies_Main::s2_qty_calc()
{
    int remote_mines_dmg = levels_data.remote_level[levels.remote_level - 1];
    if (ui->aghs_check->isChecked()){
        remote_mines_dmg = levels_data.aghs_remote_level[levels.remote_level - 1];
    }
    int remote_mines_qty = 1;
    while ((remote_mines_qty * remote_mines_dmg * (1.0 - s2.res.dmg_red) * (1.0 - s2.res.mag_res)) < s2.hp){
        remote_mines_qty++;
    }

    int prox_mines_dmg = levels_data.prox_level[levels.prox_level - 1];
    int prox_mines_qty = 1;
    while ((prox_mines_qty * prox_mines_dmg * (1.0 - s2.res.dmg_red) * (1.0 - s2.res.mag_res)) < s2.hp){
        prox_mines_qty++;
    }

    if (s2.cleared == 1){
        ui->s2_prox_qty->setText("0");
        ui->s2_remote_qty->setText("0");
    }

    else {
    s2.prox_qty = prox_mines_qty;
    ui->s2_prox_qty->setText(QVariant(s2.prox_qty).toString());
    s2.remote_qty = remote_mines_qty;
    ui->s2_remote_qty->setText(QVariant(s2.remote_qty).toString());
    }
}

void Techies_Main::s3_qty_calc()
{
    int remote_mines_dmg = levels_data.remote_level[levels.remote_level - 1];
    if (ui->aghs_check->isChecked()){
        remote_mines_dmg = levels_data.aghs_remote_level[levels.remote_level - 1];
    }
    int remote_mines_qty = 1;
    while ((remote_mines_qty * remote_mines_dmg * (1.0 - s3.res.dmg_red) * (1.0 - s3.res.mag_res)) < s3.hp){
        remote_mines_qty++;
    }

    int prox_mines_dmg = levels_data.prox_level[levels.prox_level - 1];
    int prox_mines_qty = 1;
    while ((prox_mines_qty * prox_mines_dmg * (1.0 - s3.res.dmg_red) * (1.0 - s3.res.mag_res)) < s3.hp){
        prox_mines_qty++;
    }

    if (s3.cleared == 1){
        ui->s3_prox_qty->setText("0");
        ui->s3_remote_qty->setText("0");
    }

    else {
    s3.prox_qty = prox_mines_qty;
    ui->s3_prox_qty->setText(QVariant(s3.prox_qty).toString());
    s3.remote_qty = remote_mines_qty;
    ui->s3_remote_qty->setText(QVariant(s3.remote_qty).toString());
    }
}

void Techies_Main::on_s1_hp_value_valueChanged(int arg1)
{
    s1.hp = arg1;
    s1_qty_calc();
}

void Techies_Main::on_s1_mag_res_box_valueChanged(double arg1)
{
    s1.res.mag_res = arg1 / 100.0;
    s1_qty_calc();
}

void Techies_Main::on_s1_dmg_red_box_valueChanged(double arg1)
{
    s1.res.dmg_red = arg1 / 100.0;
    s1_qty_calc();
}

void Techies_Main::on_s2_hp_value_valueChanged(int arg1)
{
    s2.hp = arg1;
    s2_qty_calc();
}

void Techies_Main::on_s2_mag_res_box_valueChanged(double arg1)
{
    s2.res.mag_res = arg1 / 100.0;
    s2_qty_calc();
}

void Techies_Main::on_s2_dmg_red_box_valueChanged(double arg1)
{
    s2.res.dmg_red = arg1 / 100.0;
    s2_qty_calc();
}

void Techies_Main::on_s3_hp_value_valueChanged(int arg1)
{
    s3.hp = arg1;
    s3_qty_calc();
}

void Techies_Main::on_s3_mag_res_box_valueChanged(double arg1)
{
    s3.res.mag_res = arg1 / 100.0;
    s3_qty_calc();
}

void Techies_Main::on_s3_dmg_red_box_valueChanged(double arg1)
{
    s3.res.dmg_red = arg1 / 100.0;
    s3_qty_calc();
}

void Techies_Main::on_magic_popout_clicked()
{
    Magic_Res magic_res;
    magic_res.Program = this;
    magic_res.setModal(true);
    magic_res.exec();
}

void Techies_Main::magic_res(double arg1)
{
    ui->magic_res->setValue(arg1);
}
