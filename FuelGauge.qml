import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 70
    height: 70

    property real value: 3.5
    property int maxValue: 7

    Canvas {
        id: gaugeCanvas
        anchors.fill: parent

        property real startAngle: 0.85 * Math.PI
        property real spanAngle: 1.3 * Math.PI

        onPaint: {
            var ctx = getContext("2d")
            ctx.reset()

            var cx = width / 2
            var cy = height / 2 + 30
            var r = 50

            var endAngle = startAngle + (value / maxValue) * spanAngle


            var gradient = ctx.createLinearGradient(cx - r, cy, cx + r, cy)
            gradient.addColorStop(0.0, "#ff0000")
            gradient.addColorStop(0.2, "#ffff00")
            gradient.addColorStop(1.0, "#00cc66")

            ctx.beginPath()
            ctx.arc(cx, cy, r, startAngle, endAngle, false)
            ctx.lineWidth = 18
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

            ctx.font = "bold italic 24px Ubuntu"


            var x = cx + Math.cos(startAngle) * (r + 28)
            var y = cy + Math.sin(startAngle) * (r + 28)
            ctx.fillText("E", x, y)


            x = cx + Math.cos(startAngle + spanAngle) * (r + 28)
            y = cy + Math.sin(startAngle + spanAngle) * (r + 28)
            ctx.fillText("F", x, y)


            for (var i = 0; i <= maxValue; ++i) {
                var fraction = i / maxValue
                var angle = startAngle + fraction * spanAngle


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
}
