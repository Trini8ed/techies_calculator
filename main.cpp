#include <QApplication>
#include "Techies_Main.h"
#include "Magic_Res.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Techies_Main w;
    w.show();

    return a.exec();
}
