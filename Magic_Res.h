#ifndef MAGIC_RES_H
#define MAGIC_RES_H

#include <QDialog>
#include <QListWidget>
#include <QCheckBox>
#include <QMainWindow>

namespace Ui {
class Magic_Res;
}

class Magic_Res : public QDialog
{
    Q_OBJECT

public:
    explicit Magic_Res(QWidget *parent = 0);
    ~Magic_Res();

    void clear_settings();

signals:
    void notifyMessageSentMag(const double& arg1);

private slots:

    void on_magic_res_widget_itemPressed(QListWidgetItem *item);

    void update(QListWidgetItem *item);

    void on_magic_res_widget_itemDoubleClicked(QListWidgetItem *item);

    void do_magic();

    void on_open_close_accepted();

private:
    Ui::Magic_Res *mag;
};

#endif // MAGIC_RES_H
