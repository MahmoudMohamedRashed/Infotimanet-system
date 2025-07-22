import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 400
    height: 400
    property int value: 125


    Canvas {

        id: gaugeCanvas
        anchors.fill: parent

        property int maxValue: 250
        property real startAngle: 0.85 * Math.PI
        property real spanAngle: 1.3 * Math.PI

        onPaint: {
            var ctx = getContext("2d")
            ctx.reset()

            var cx = width / 2
            var cy = height / 2 + 70
            var r = 185

            var endAngle = startAngle + (value / maxValue) * spanAngle


            var gradient = ctx.createLinearGradient(cx - r, cy, cx + r, cy)
            gradient.addColorStop(0.0, "#00cc66")
            gradient.addColorStop(0.85, "#ffff00")
            gradient.addColorStop(1.0, "#ff0000")



            ctx.beginPath()
            ctx.arc(cx, cy, r, startAngle, endAngle, false)
            ctx.lineWidth = 14
            ctx.strokeStyle = gradient
            ctx.stroke()


            ctx.fillStyle = "white"
            ctx.font = "bold 16px Ubuntu"
            ctx.textAlign = "center"
            ctx.textBaseline = "middle"

            ctx.beginPath();
            ctx.arc(cx, cy, r + 55, startAngle, 0.15 * Math.PI, false);
            ctx.lineWidth = 7
            ctx.strokeStyle = "white";
            ctx.stroke();


            var steps = 10
            for (var i = 0; i <= steps; ++i) {
                var fraction = i / steps
                var angle = startAngle + fraction * spanAngle
                var num = Math.round(fraction * maxValue)

                var textRadius = r + 25
                var x = cx + Math.cos(angle) * textRadius
                var y = cy + Math.sin(angle) * textRadius

                ctx.fillText(num.toString(), x, y)

                var tickStart = r + 40
                var tickEnd = r + 58
                var x1 = cx + Math.cos(angle) * tickStart
                var y1 = cy + Math.sin(angle) * tickStart
                var x2 = cx + Math.cos(angle) * tickEnd
                var y2 = cy + Math.sin(angle) * tickEnd

                ctx.beginPath()
                ctx.moveTo(x1, y1)
                ctx.lineTo(x2, y2)
                ctx.lineWidth = 4
                ctx.strokeStyle = "white"
                ctx.stroke()
            }
        }

        Timer {
            interval: 100
            running: true
            repeat: true
            onTriggered: gaugeCanvas.requestPaint()
        }
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height / 2 + 100
        text: value + " Km/h"
        color: "white"
        font.pixelSize: 56
        font.family: "Ubuntu"
        font.bold: true
        font.italic: true
    }
}
