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
        id: ring
        div: 40
        angle: 120
        startAngle: 120
        endAngle: 420
        SequentialAnimation on angle {
            NumberAnimation { to: ring.endAngle; duration: 5000; easing.type: Easing.InOutQuad }
            NumberAnimation { to: ring.startAngle; duration: 5000; easing.type: Easing.InOutQuad }
            loops: Animation.Infinite
        }
    }
}
