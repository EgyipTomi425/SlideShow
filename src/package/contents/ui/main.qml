/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

import QtQuick 2.1
import QtQuick.Layouts 1.1
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.components 3.0 as PlasmaComponents3

Item {
    Plasmoid.fullRepresentation: ColumnLayout {
        anchors.fill: parent

        MouseArea {
            id: imageArea
            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: Plasmoid.nativeInterface.nextImage()

            Image {
                id: image
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                source: Plasmoid.nativeInterface.currentImage
            }
        }

        PlasmaComponents3.Label {
            Layout.alignment: Qt.AlignCenter
            text: Plasmoid.nativeInterface.currentImageName
        }
    }
}
