#ifndef DMG_RED_H
#define DMG_RED_H

#include <QDialog>
#include <QListWidget>
#include <QCheckBox>
#include <QMainWindow>

namespace Ui {
class Dmg_Red;
}

class Dmg_Red : public QDialog
{
    Q_OBJECT

signals:
    void notifyMessageSentDmg(const double& arg1);

public:
    explicit Dmg_Red(QWidget *parent = 0);
    ~Dmg_Red();

    void clear_settings();

private slots:

    void on_dmg_red_widget_itemPressed(QListWidgetItem *item);

    void update(QListWidgetItem *item);

    void on_dmg_red_widget_itemDoubleClicked(QListWidgetItem *item);

    void do_magic();

    void on_open_close_accepted();

private:
    Ui::Dmg_Red *dmg;
};

#endif // DMG_RED_H
