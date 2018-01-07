#ifndef SCREEN_DATA_H
#define SCREEN_DATA_H

#include <QObject>
#include <QScreen>
#include <QPixmap>

class Screen_Data : public QObject
{
    Q_OBJECT
public:
    explicit Screen_Data(QObject *parent = nullptr);

signals:

public slots:

    void QPixMap_Data(QPixmap game);
};

#endif // SCREEN_DATA_H
