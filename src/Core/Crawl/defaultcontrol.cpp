//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "defaultcontrol.h"

namespace CRAWL {

DefaultControl::DefaultControl() {

}

QString DefaultControl::initQmlView() const {
    return "qrc:/CrawlModule/DefaultMenu.qml";
}
}
