//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#include "claster.h"
#include "singleclasterworlditem.h"
#include "quasarapp.h"

SingleClasterWorldItem::SingleClasterWorldItem() {

}

void SingleClasterWorldItem::setClaster(Claster *claster) {
    if (parentClasters().size() > 0) {
        debug_assert(parentClasters().size() > 1, "Internal error occured, The singleClaster object have multiple claster parents!!");

        Claster* parent = *parentClasters().begin();
        parent->remove(this);
        removeClaster(parent);
    }

    ClasterItem::setClaster(claster);
}
