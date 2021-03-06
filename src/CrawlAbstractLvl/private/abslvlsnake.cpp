//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "abslvlsnake.h"
#include "abslvlsnakeitem.h"

AbsLvlSnake::AbsLvlSnake(): Snake("Snake") {
    setBreakingForce(50);
    setAngularVelocity(100);
    setColor("#90faaa");
    setMash("qrc:/mesh/meshes/SnakePatternHead.mesh");
    setSize({2,1,1});

    registerItemType<AbsLvlSnakeItem>();
}

void AbsLvlSnake::onIntersects(const IWorldItem *item) {
    Q_UNUSED(item);
}
