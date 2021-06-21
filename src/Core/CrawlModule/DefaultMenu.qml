//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

import QtQuick 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls 2.15

AbstractMenuView {
    Button {
        text: qsTr("Back to menu.")
        onClicked: {
            if (model) {
                model.backToMenu()
            }
        }
    }
}