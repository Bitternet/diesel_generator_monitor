import QtQuick 2.0
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

    CircularGauge {
                    id: tachometer
                    width: parent.width
                    height:  parent.height * 0.9
                    value: 0
                    maximumValue: 18
                    anchors.verticalCenter: parent.verticalCenter

                    Behavior on value {
                        NumberAnimation {
                            duration: 1000
                        }
                    }

                    style: TachometerStyle {
                       txtZN: "x1000"
                       maxV: 9
                       tickMin: 16
                       tickMax: 18
                       txtZNbottom: "об/мин"
                       flagWidget: true
                       valPower: tachometer.value
                    }
                }
   Connections{
        target: p_diselGen_tab
        onDataPowerChanged: tachometer.value = valueToPower
    }
}
