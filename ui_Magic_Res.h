/********************************************************************************
** Form generated from reading UI file 'Magic_Res.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGIC_RES_H
#define UI_MAGIC_RES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Magic_Res
{
public:
    QDialogButtonBox *open_close;
    QListWidget *magic_res_widget;
    QPushButton *pushButton;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QDialog *Magic_Res)
    {
        if (Magic_Res->objectName().isEmpty())
            Magic_Res->setObjectName(QStringLiteral("Magic_Res"));
        Magic_Res->resize(350, 630);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Magic_Res->sizePolicy().hasHeightForWidth());
        Magic_Res->setSizePolicy(sizePolicy);
        Magic_Res->setMinimumSize(QSize(350, 630));
        Magic_Res->setMaximumSize(QSize(350, 630));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/null_feild.png"), QSize(), QIcon::Normal, QIcon::Off);
        Magic_Res->setWindowIcon(icon);
        open_close = new QDialogButtonBox(Magic_Res);
        open_close->setObjectName(QStringLiteral("open_close"));
        open_close->setGeometry(QRect(180, 590, 161, 32));
        open_close->setOrientation(Qt::Horizontal);
        open_close->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        magic_res_widget = new QListWidget(Magic_Res);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/cloak.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem->setCheckState(Qt::Unchecked);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/hood.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem1->setCheckState(Qt::Unchecked);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/glimmer.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem2->setCheckState(Qt::Unchecked);
        __qlistwidgetitem2->setIcon(icon3);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem3->setCheckState(Qt::Unchecked);
        __qlistwidgetitem3->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/magic_res.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(12);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem4->setCheckState(Qt::Unchecked);
        __qlistwidgetitem4->setFont(font);
        __qlistwidgetitem4->setIcon(icon4);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem5->setCheckState(Qt::Unchecked);
        __qlistwidgetitem5->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/spell_sheild.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem6->setCheckState(Qt::Unchecked);
        __qlistwidgetitem6->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/leveled_talent.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem7->setCheckState(Qt::Unchecked);
        __qlistwidgetitem7->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/berserkers_blood.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem8->setCheckState(Qt::Unchecked);
        __qlistwidgetitem8->setIcon(icon7);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/flesh_heap.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem9->setCheckState(Qt::Unchecked);
        __qlistwidgetitem9->setIcon(icon8);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem10->setCheckState(Qt::Unchecked);
        __qlistwidgetitem10->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem11->setCheckState(Qt::Unchecked);
        __qlistwidgetitem11->setIcon(icon6);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/bear_res.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem12 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem12->setCheckState(Qt::Unchecked);
        __qlistwidgetitem12->setIcon(icon9);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/corrosive_skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem13 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem13->setCheckState(Qt::Unchecked);
        __qlistwidgetitem13->setIcon(icon10);
        QListWidgetItem *__qlistwidgetitem14 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem14->setCheckState(Qt::Unchecked);
        __qlistwidgetitem14->setIcon(icon6);
        QListWidgetItem *__qlistwidgetitem15 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem15->setCheckState(Qt::Unchecked);
        __qlistwidgetitem15->setIcon(icon6);
        QListWidgetItem *__qlistwidgetitem16 = new QListWidgetItem(magic_res_widget);
        __qlistwidgetitem16->setCheckState(Qt::Unchecked);
        __qlistwidgetitem16->setIcon(icon6);
        magic_res_widget->setObjectName(QStringLiteral("magic_res_widget"));
        magic_res_widget->setGeometry(QRect(10, 10, 331, 571));
        magic_res_widget->setFont(font);
        magic_res_widget->setFrameShape(QFrame::WinPanel);
        magic_res_widget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        magic_res_widget->setAutoScrollMargin(16);
        magic_res_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        magic_res_widget->setProperty("showDropIndicator", QVariant(false));
        magic_res_widget->setDragEnabled(false);
        magic_res_widget->setAlternatingRowColors(true);
        magic_res_widget->setSelectionMode(QAbstractItemView::NoSelection);
        magic_res_widget->setIconSize(QSize(32, 32));
        magic_res_widget->setTextElideMode(Qt::ElideRight);
        magic_res_widget->setMovement(QListView::Static);
        magic_res_widget->setFlow(QListView::TopToBottom);
        magic_res_widget->setResizeMode(QListView::Fixed);
        magic_res_widget->setLayoutMode(QListView::SinglePass);
        magic_res_widget->setSpacing(2);
        magic_res_widget->setViewMode(QListView::ListMode);
        magic_res_widget->setModelColumn(0);
        magic_res_widget->setUniformItemSizes(true);
        magic_res_widget->setSortingEnabled(false);
        pushButton = new QPushButton(Magic_Res);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 590, 61, 31));
        doubleSpinBox = new QDoubleSpinBox(Magic_Res);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(80, 590, 101, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        doubleSpinBox->setFont(font1);
        doubleSpinBox->setReadOnly(true);
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setDecimals(6);
        doubleSpinBox->setMinimum(-100);
        doubleSpinBox->setValue(25);

        retranslateUi(Magic_Res);
        QObject::connect(open_close, SIGNAL(accepted()), Magic_Res, SLOT(accept()));
        QObject::connect(open_close, SIGNAL(rejected()), Magic_Res, SLOT(reject()));

        QMetaObject::connectSlotsByName(Magic_Res);
    } // setupUi

    void retranslateUi(QDialog *Magic_Res)
    {
        Magic_Res->setWindowTitle(QApplication::translate("Magic_Res", "Magic Resistance Grabber", Q_NULLPTR));

        const bool __sortingEnabled = magic_res_widget->isSortingEnabled();
        magic_res_widget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = magic_res_widget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Magic_Res", "Cloak", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = magic_res_widget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Magic_Res", "Hood of Defiance", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = magic_res_widget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Magic_Res", "Glimmer Cape", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = magic_res_widget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Magic_Res", "Glimmer Cape - Glimmer", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = magic_res_widget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Magic_Res", "Pipe Of Insight", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = magic_res_widget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Magic_Res", "Pipe Of Insight Aura", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem6 = magic_res_widget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Magic_Res", "Anti-Mage - Spell Sheild", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem7 = magic_res_widget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("Magic_Res", "Anti-Mage - Spell Sheild Talent", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem8 = magic_res_widget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("Magic_Res", "Huskar - Berserker's Blood", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem9 = magic_res_widget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("Magic_Res", "Pudge - Flesh Heap", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem10 = magic_res_widget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("Magic_Res", "Rubick - Null Field", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem11 = magic_res_widget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("Magic_Res", "Rubick - Null Field Talent", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem12 = magic_res_widget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("Magic_Res", "Spirit Bear - Demolish", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem13 = magic_res_widget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("Magic_Res", "Viper - Corrosive Skin", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem14 = magic_res_widget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("Magic_Res", "Viper - Corrosive Skin Talent", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem15 = magic_res_widget->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("Magic_Res", "Keeper Of The Light - Talent", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem16 = magic_res_widget->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("Magic_Res", "Earthshaker Talent", Q_NULLPTR));
        magic_res_widget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("Magic_Res", "Update", Q_NULLPTR));
        doubleSpinBox->setSpecialValueText(QString());
    } // retranslateUi

};

namespace Ui {
    class Magic_Res: public Ui_Magic_Res {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGIC_RES_H
