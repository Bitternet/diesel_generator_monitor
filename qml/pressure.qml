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
                    id: pressure
                    width: parent.width
                    height:  parent.height * 0.9
                    value: 0
                    maximumValue: 10
                    anchors.verticalCenter: parent.verticalCenter

                    Behavior on value {
                        NumberAnimation {
                            duration: 1000
                        }
                    }

                    style: TachometerStyle {
                        maxV: 10
                        tickMin: 9
                        tickMax: 10
                        icoSource: "qrc:/new/images/images/oil.png"
                        txtZNbottom: "бар"
                        valPressure: pressure.value
                }
}
    Connections{
        target: p_diselGen_tab
        onDataPressureChanged: pressure.value = dataToPressure
    }
}

