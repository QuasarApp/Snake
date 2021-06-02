#include "box.h"

#include <QColor>

Box::Box(double x, double y):
    ItemWorld (x, y) {

    this->setSize(10, 10);
    setMash("#Cube");

    setColor(QColor(100, 100, 100).name());
}

