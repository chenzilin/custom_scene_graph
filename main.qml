import QtQuick 2.2
import QtQuick.Window 2.1
import Ring 1.0

Window {
    visible: true
    width: 360
    height: 360

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    Ring {
        SequentialAnimation on div {
            NumberAnimation { to: 50; duration: 5000; easing.type: Easing.InOutQuad }
            NumberAnimation { to: 4; duration: 5000; easing.type: Easing.InOutQuad }
            loops: Animation.Infinite
        }
    }
}
