import QtQuick 2.15
import QtQuick3D 1.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


View3D {
    id: scene;

    property var model: null;

    PerspectiveCamera {
        id: camera
        position: Qt.vector3d(0, 0, 100)
        eulerRotation.y: -45
        eulerRotation.z: -90

    }

    DirectionalLight {
    }

    environment: SceneEnvironment {
        id: background
        clearColor: window.color
        backgroundMode: SceneEnvironment.SkyBox
        //probeOrientation: Qt.vector3d(0, -90, 0)

        lightProbe: Texture {
            source: "qrc:/hdr/res/hdr/lebombo_2k.hdr"
        }
    }

    Node {
        id: mainScane
    }

    Timer {
        id: autoTimer;
        repeat: true;
        running: showMenu;
        interval: 1000
        onTriggered: {
            interval = Math.random() * 600
            scene.model.buttonPress();
        }
    }

    Component.onCompleted: {
        updateBackgroundColor(0);
        model.handleNewGame();

    }

    MouseArea {
        anchors.fill: parent;

        onClicked: {
            if (!model || showMenu) {
                return;
            }

            model.buttonPress();
        }
    }

    Button {
        id: returnToMenu;

        text: "<<"

        anchors.left: parent.left
        anchors.leftMargin: metrix.gamePt

        anchors.top: parent.top
        anchors.topMargin: metrix.gamePt
        z: 1

        onClicked: {
            if (model)
                model.showMenu = true;
        }

        visible: !showMenu
    }

    Button {
        id: pause

        text: (isPause)?  "▶" :"||"

        anchors.left: returnToMenu.right
        anchors.leftMargin: metrix.gamePt

        anchors.top: parent.top
        anchors.topMargin: metrix.gamePt
        z: returnToMenu.z

        onClicked: {
            isPause = !isPause;
            if (model) model.setPause(isPause);
        }

        visible: !showMenu

    }

    Button {
        id: long_
        Label {
            anchors.fill: parent;

            textFormat: Text.AutoText
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap

            text: qsTr("lvl long: ") + ((model)? model.long_: "0")
        }

        width: 35 * metrix.gamePt;
        height: pause.height;

        anchors.left: pause.right
        anchors.leftMargin: metrix.gamePt

        anchors.top: parent.top
        anchors.topMargin: metrix.gamePt
        z: returnToMenu.z

        visible: !showMenu

    }

    Button {
        Label {
            anchors.fill: parent;

            textFormat: Text.AutoText
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap

            text: qsTr("general long: ") + ((model)? model.generalLong: "0")
        }

        width: 35 * metrix.gamePt;
        height: long_.height;

        anchors.left: long_.right
        anchors.leftMargin: metrix.gamePt

        anchors.top: parent.top
        anchors.topMargin: metrix.gamePt
        z: returnToMenu.z

        visible: !showMenu

    }
}
