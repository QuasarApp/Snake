//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "abslvlsnakeitem.h"

AbsLvlSnakeItem::AbsLvlSnakeItem():CRAWL::SnakeItem("AbstractSnakeItem") {
    setMash("qrc:/mesh/meshes/SnakePatternBody.mesh");
    setColor("#20aa9a");
    setSize({1,1,1});
}

void AbsLvlSnakeItem::onIntersects(const IWorldItem *item) {
    Q_UNUSED(item);

}
