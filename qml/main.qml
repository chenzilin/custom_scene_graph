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
		div: 60
		ro: 220
		ri: 140
		angle: 120
		startAngle: 120
		endAngle: 420
		tex: ":/images/sekuai.png"
		SequentialAnimation on angle {
			NumberAnimation { to: ring.endAngle; duration: 5000; easing.type: Easing.InOutQuad }
			NumberAnimation { to: ring.startAngle; duration: 5000; easing.type: Easing.InOutQuad }
			loops: Animation.Infinite
		}
	}
}
