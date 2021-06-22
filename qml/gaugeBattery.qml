import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Item {

    Rectangle{
        width: parent.width
        height: parent.height
        color: "#f4f4f4"
    }

       property string icoChange: ""
       property string textChange: ""
       property string textMin: ""
       property string textMax: ""
       property color minWarning: Qt.rgba(0.5, 0, 0, 1)
       property color maxWarning: Qt.rgba(0.5, 0, 0, 1)

                CircularGauge {
                    id: batteryGauge
                    value: 0
                    maximumValue: 1
                    y: parent.height / 4
                    width: parent.width
                    height: parent.height
                    property string textValue: "-"

                    Behavior on value {
                        NumberAnimation {
                            duration: 1000
                        }
                    }

                    style: IconGaugeStyle {
                        id: fuelGaugeStyle

                        icon: icoChange
                        minWarningColor: minWarning
                        maxWarningColor: maxWarning
                        flagArc: "#000000"

                        textV: batteryGauge.textValue

                        tickmarkLabel: Text {
                            color: "black"
                            visible: styleData.value === 0 || styleData.value === 1
                            font.pixelSize: fuelGaugeStyle.toPixels(0.2)
                            text: styleData.value === 0 ? textMin : (styleData.value === 1 ? textMax : "")
        }
   }
 }
              Connections{
                   target: p_diselGen_tab
                   onDataBatteryGaugeChanged: { batteryGauge.value = dataToBatteryGauge; batteryGauge.textValue = valueToBatteryGauge}
   }
}

