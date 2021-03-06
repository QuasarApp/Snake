//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "clasteritem.h"
#include "groundclaster.h"
#include "iworld.h"

namespace CRAWL {


GroundClaster::GroundClaster(const QString &name,
                 const QString &viewTempalte,
                 QObject *ptr):
    IWorldItem(name, viewTempalte, ptr) {


}

void GroundClaster::render(unsigned int ) {
    const IWorldItem *playerObject = getPlayer();

    if (!_itemsOrder.size()) {
        QuasarAppUtils::Params::log("The GroundClaster do not have any claster items.",
                                    QuasarAppUtils::Error);
        return;
    }

    auto object = _itemsOrder.at(_index % _itemsOrder.size());

    if (playerObject->position().distanceToPoint(object->position()) >
            newObjectDistance()) {

        auto prewObject = _itemsOrder.at((_index - 1) % _itemsOrder.size());

        object->setposition({prewObject->position().x() + newObjectDistance(),
                             playerObject->position().y(),
                             object->position().z() - static_cast<float>(0.0001)});

        _index++;
    }
}

void GroundClaster::add(ClasterItem *object) {
    object->setX(newObjectDistance() * _itemsOrder.count());
    _itemsOrder.push_back(object);

    Claster::add(object);
}

void GroundClaster::remove(ClasterItem *object) {
    _itemsOrder.push_back(object);

    Claster::remove(object);
}

void GroundClaster::remove(int id) {
    _itemsOrder.push_back(objects().value(id));

    Claster::remove(id);
}

void GroundClaster::init() {
    generateItems();
}

int GroundClaster::newObjectDistance() const {
    return 500;
}

unsigned int GroundClaster::itemsCount() const {
    return 3;
}


}
