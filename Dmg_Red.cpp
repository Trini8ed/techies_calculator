#include "Dmg_Red.h"
#include "ui_Dmg_Red.h"

//_______________________
//Damage Reduction Arrays
//_______________________

struct sub {
    double not_leveled;
    double leveled;
};

struct dmg_red_abilities {
    sub bristle;
    double centaur;
    double io;
    double medusa;
    double burrow;
    sub spectre;
    double ursa;
    double visage;
};

double global_dmg_red = 0.0;

const dmg_red_abilities array = {
    //Bristle "Side, Rear"
    {0.2,0.4},
    //Centaur
    0.4,
    //Io
    0.2,
    //Medusa
    0.6,
    //Burrow
    0.4,
    //Spectre
    {0.22,0.30},
    //Ursa
    0.8,
    //Visage
    0.2};

Dmg_Red::Dmg_Red(QWidget *parent) :
    QDialog(parent),
    dmg(new Ui::Dmg_Red)
{
    dmg->setupUi(this);
}

Dmg_Red::~Dmg_Red()
{
    delete dmg;
}

void Dmg_Red::do_magic()
{
    double dmg_red = 1 - 0.0;

    if (dmg->dmg_red_widget->item(0)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.bristle.not_leveled);
    }
    if (dmg->dmg_red_widget->item(1)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.bristle.leveled);
    }
    if (dmg->dmg_red_widget->item(2)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.centaur);
    }
    if (dmg->dmg_red_widget->item(3)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.io);
    }
    if (dmg->dmg_red_widget->item(4)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.medusa);
    }
    if (dmg->dmg_red_widget->item(5)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.burrow);
    }
    if (dmg->dmg_red_widget->item(6)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.spectre.not_leveled);
    }
    if (dmg->dmg_red_widget->item(7)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.spectre.leveled);
    }
    if (dmg->dmg_red_widget->item(8)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.ursa);
    }
    if (dmg->dmg_red_widget->item(9)->checkState() == Qt::Checked){
        dmg_red *= (1 - array.visage);
    }

    dmg_red = 1 - dmg_red;

    dmg->dmg_red_value->setValue((dmg_red) * 100.0);

    global_dmg_red = dmg_red;
}

void Dmg_Red::update(QListWidgetItem *item)
{
    if (item->checkState() == Qt::Unchecked){
        item->setCheckState(Qt::Checked);
    }
    else item->setCheckState(Qt::Unchecked);

    do_magic();
}

void Dmg_Red::on_dmg_red_widget_itemPressed(QListWidgetItem *item)
{
    update(item);
}

void Dmg_Red::on_dmg_red_widget_itemDoubleClicked(QListWidgetItem *item)
{
    update(item);
}

void Dmg_Red::on_open_close_accepted()
{
    emit notifyMessageSentDmg(global_dmg_red);
    global_dmg_red = 0.0;

    Dmg_Red();
}

void Dmg_Red::clear_settings()
{
    global_dmg_red = 0.0;
    dmg->dmg_red_value->setValue(global_dmg_red * 100.0);

    for (int i = 0; i < 10; i++){
        dmg->dmg_red_widget->item(i)->setCheckState(Qt::Unchecked);
    }
}
