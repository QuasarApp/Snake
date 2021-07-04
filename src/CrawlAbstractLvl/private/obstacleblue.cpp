//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "obstacleblue.h"

ObstacleBlue::ObstacleBlue() : IWorldItem("OstacleBlue") {
    setMash("qrc:/mesh/meshes/ObstacleBlue.mesh");
    setSize({10,10,10});
    setZ(0);
}

void ObstacleBlue::onIntersects(const IWorldItem *item) {
        Q_UNUSED(item);
}