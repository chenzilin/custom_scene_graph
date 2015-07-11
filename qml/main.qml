import QtQuick 2.4
import QtQuick.Window 2.1
import Ring 1.0

Window {
	visible: true
	width: 480
	height: 480
	color: "black"

	Ring {
		id: ring
		x: 20
		y: 20
		ro: 173
		ri: 135
		angle: 317
		startAngle: 38
		endAngle: 317
		clockwise: true
		tex: "qrc:/images/ring.png"
		SequentialAnimation on angle {
			NumberAnimation { to: ring.startAngle; duration: 5000; easing.type: Easing.InOutQuad }
			NumberAnimation { to: ring.endAngle; duration: 5000; easing.type: Easing.InOutQuad }
			loops: Animation.Infinite
		}
	}
}
