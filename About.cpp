#include "About.h"
#include "ui_About.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

//    setWindowFlags(Qt::WindowStaysOnTopHint);
}

About::~About()
{
    delete ui;
}
