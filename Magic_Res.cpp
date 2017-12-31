#include "Magic_Res.h"
#include "ui_Magic_Res.h"

//_______________________
//Magic Resistance Arrays
//_______________________

struct sub {
    double not_leveled;
    double leveled;
};

struct mag_items {
    double cloak;
    double hood;
    sub glimmer;
    sub pipe;
};

struct mag_abilities {
    sub antimage;
    double huskar;
    double pudge;
    sub rubick;
    double bear;
    sub viper;
    double kotl;
    double earthshaker;
};

struct global {
    mag_items items;
    mag_abilities abilities;
};

const global array = {
     //Cloak
     {0.15,
     //Hood
     0.25,
     //Glimmer, Then Active
     {0.15,0.45},
     //Pipe
     {0.37,0.1}},
     //Anti-Mage
     {{0.5,0.75},
     //Huskar
     0.5,
     //Pudge
     0.12,
     //Rubick
     {0.22,0.27},
     //Bear
     0.33,
     //Viper
     {0.25,0.31},
     //Keeper of the light
     0.4,
     //Eathshaker
     0.5}
};

double global_magic_res = 0.25;

Magic_Res::Magic_Res(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Magic_Res)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);
}

Magic_Res::~Magic_Res()
{
    delete ui;
}

void Magic_Res::do_magic()
{
    double mag_res = 1 - global_magic_res;

    if (ui->magic_res_widget->item(0)->checkState() == Qt::Checked){
        mag_res *= (1 - array.items.cloak);
    }
    if (ui->magic_res_widget->item(1)->checkState() == Qt::Checked){
        mag_res *= (1 - array.items.hood);
    }
    if (ui->magic_res_widget->item(2)->checkState() == Qt::Checked){
        mag_res *= (1 - array.items.glimmer.not_leveled);
    }
    if (ui->magic_res_widget->item(3)->checkState() == Qt::Checked){
        mag_res *= (1 - array.items.glimmer.leveled);
    }
    if (ui->magic_res_widget->item(4)->checkState() == Qt::Checked){
        mag_res *= (1 - array.items.pipe.not_leveled);
    }
    if (ui->magic_res_widget->item(5)->checkState() == Qt::Checked){
        mag_res *= (1 - array.items.pipe.leveled);
    }
    if (ui->magic_res_widget->item(6)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.antimage.not_leveled);
    }
    if (ui->magic_res_widget->item(7)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.antimage.leveled);
    }
    if (ui->magic_res_widget->item(8)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.huskar);
    }
    if (ui->magic_res_widget->item(9)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.pudge);
    }
    if (ui->magic_res_widget->item(10)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.rubick.not_leveled);
    }
    if (ui->magic_res_widget->item(11)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.rubick.leveled);
    }
    if (ui->magic_res_widget->item(12)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.bear);
    }
    if (ui->magic_res_widget->item(13)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.viper.not_leveled);
    }
    if (ui->magic_res_widget->item(14)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.viper.leveled);
    }
    if (ui->magic_res_widget->item(15)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.kotl);
    }
    if (ui->magic_res_widget->item(16)->checkState() == Qt::Checked){
        mag_res *= (1 - array.abilities.earthshaker);
    }
    ui->doubleSpinBox->setValue((1 - mag_res) * 100);
}

void Magic_Res::update(QListWidgetItem *item)
{
    if (item->checkState() == Qt::Unchecked){
        item->setCheckState(Qt::Checked);
    }
    else item->setCheckState(Qt::Unchecked);

    do_magic();
}


void Magic_Res::on_magic_res_widget_itemPressed(QListWidgetItem *item)
{
    update(item);
}

void Magic_Res::on_magic_res_widget_itemDoubleClicked(QListWidgetItem *item)
{
    update(item);
}

void Magic_Res::on_open_close_accepted()
{

}
