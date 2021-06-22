import QtQuick 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

DashboardGaugeStyle {
    id: tachometerStyle
    tickmarkStepSize: 1
    labelStepSize: 1
    needleLength: toPixels(0.85)
    needleBaseWidth: toPixels(0.08)
    needleTipWidth: toPixels(0.03)

    property string txtZN: ""
    property string txtZNbottom: ""
    property int maxV: 0
    property int tickMin: 0
    property int tickMax: 0
    property string icoSource: ""
    property string valPressure: "-"
    property string valPower: "-"
    property bool flagWidget: false

    tickmark: Rectangle {
        implicitWidth: toPixels(0.03)
        antialiasing: true
        implicitHeight: toPixels(0.08)
        color: styleData.index === tickMin || (styleData.index === tickMax || styleData.index === tickMax - 1) ? Qt.rgba(0.5, 0, 0, 1) : "black"
    }

    minorTickmark: null

    tachFlag: true

    tickmarkLabel: Text {
        font.pixelSize: Math.max(6, toPixels(0.12))
        text: styleData.value
        color: styleData.index === tickMin || (styleData.index === tickMax || styleData.index === tickMax - 1) ? Qt.rgba(0.5, 0, 0, 1) : "black"
        antialiasing: true
    }

    background: Canvas {
        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();
            paintBackground(ctx);

            ctx.beginPath();
            ctx.lineWidth = tachometerStyle.toPixels(0.08);
            ctx.strokeStyle = Qt.rgba(0.5, 0, 0, 1);
            var warningCircumference = maximumValueAngle - minimumValueAngle * 0.1;
            var startAngle = maximumValueAngle - 90;
            ctx.arc(outerRadius, outerRadius,
                // Start the line in from the decorations, and account for the width of the line itself.
                outerRadius - tickmarkInset - ctx.lineWidth / 2,
                degToRad(startAngle - angleRange / maxV + angleRange * 0.015),
                degToRad(startAngle - angleRange * 0.015), false);
            ctx.stroke();
        }

        Text {
            id: rpmText
            font.pixelSize: tachometerStyle.toPixels(0.3)
            text: flagWidget === true ? valPower.substring(0,4) : valPressure.substring(0,3)
            color: "steelblue"
            horizontalAlignment: Text.AlignRight
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.verticalCenter
            anchors.topMargin: 20

            property int rpmInt: 0
        }
        Text {
            text: txtZN
            color: "dimgrey"
            font.pixelSize: tachometerStyle.toPixels(0.1)
            anchors.top: parent.top
            anchors.topMargin: parent.height / 4
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            text: txtZNbottom
            color: "black"
            font.pixelSize: tachometerStyle.toPixels(0.1)
            anchors.top: rpmText.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Image {
            source: icoSource
            anchors.bottom: parent.verticalCenter
            anchors.bottomMargin: toPixels(0.3)
            anchors.horizontalCenter: parent.horizontalCenter
            width: toPixels(0.4)
            height: width
            fillMode: Image.PreserveAspectFit
        }
    }
}
