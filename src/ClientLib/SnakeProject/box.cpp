#include "box.h"

#include <QColor>

Box::Box(double x, double y):
    ItemWorld (x, y, "3dPrimitive") {

    this->setSize(10, 10);

    setColor(QColor(100, 100, 100).name());
}

