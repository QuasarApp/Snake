#ifndef SNAKE_H
#define SNAKE_H

#define SPEEDSNAKE 10

#include <QVector>
#include "head.h"
#include "baseclass.h"

class GuiObject;

class Snake : public BaseClass
{
private:
    QVector<Head*> items;
    double speed;
    bool isClick;
    int countClick;
public:
    Snake();
    ~Snake() override;

    const QRectF &getRiger() const;
    void render() override;
    QMap<int, GuiObject *> init(int size, double speed);
    const QVector<Head*>& getItems() const;
    double getMovedLong() const;
};

#endif // SNAKE_H
