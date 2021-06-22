import QtQuick 2.0

Item {
    id: panel
   // opacity: 0.0

    property string txt_a_FAZA_A: "-"
    property string txt_v_FAZA_A: "-"
    property string txt_a_FAZA_B: "-"
    property string txt_v_FAZA_B: "-"
    property string txt_a_FAZA_C: "-"
    property string txt_v_FAZA_C: "-"

    Rectangle{
        width: parent.width
        height: parent.height
        color: "#f4f4f4"
    }

    Canvas
    {
        id: canvasf1
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");

            ctx.lineWidth = 5;
            ctx.strokeStyle = "steelblue"
            ctx.beginPath()
            ctx.moveTo(canvasf1.width/10, canvasf1.height/2);
            ctx.lineTo((canvasf1.width/3)+ parent.width / 4, canvasf1.height/2);
            ctx.moveTo(((canvasf1.width/3)+ parent.width / 4)- 2.5, canvasf1.height/2);
            ctx.lineTo((canvasf1.width/3)+ parent.width / 4, canvasf1.height/4.8);
            ctx.moveTo(((canvasf1.width/3)+ parent.width / 4)- 2.5, (canvasf1.height/4.8));
            ctx.lineTo((canvasf1.width/3)+ parent.width / 3, canvasf1.height/4.8);
            ctx.stroke();
        }
    }

    Canvas
    {
        id: canvasf2
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");

            ctx.lineWidth = 5;
            ctx.strokeStyle = "steelblue"
            ctx.beginPath()
            ctx.moveTo(canvasf2.width/10, canvasf2.height/1.9);
            ctx.lineTo((canvasf2.width/2.5)+ parent.width / 4, canvasf2.height/1.9);
            ctx.stroke();
        }
    }

    Canvas
    {
        id: canvasf3
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");

            ctx.lineWidth = 5;
            ctx.strokeStyle = "steelblue"
            ctx.beginPath()
            ctx.moveTo(canvasf3.width/10, canvasf3.height/1.8);
            ctx.lineTo((canvasf3.width/3)+ parent.width / 4, canvasf3.height/1.8);
            ctx.moveTo(((canvasf3.width/3)+ parent.width / 4) - 2.5, canvasf3.height/1.8);
            ctx.lineTo((canvasf3.width/3)+ parent.width / 4, canvasf3.height/1.2);
            ctx.moveTo(((canvasf3.width/3)+ parent.width / 4)- 2.5, canvasf3.height/1.2);
            ctx.lineTo((canvasf3.width/3)+ parent.width / 3, canvasf3.height/1.2);
            ctx.stroke();
        }
    }

    Image {
        id: name
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        source: "qrc:/new/images/images/dga_color.png"
    }

    Rectangle{
        width: parent.width / 3
        height: parent.height / 5
        color: "steelblue"
        anchors.left: parent.horizontalCenter
        anchors.bottom: parent.verticalCenter
        anchors.bottomMargin: parent.height / 5.2
        anchors.leftMargin:  parent.width / 8
    }

    Rectangle{
        width: parent.width / 3
        height: parent.height / 5
        color: "steelblue"
        anchors.left: parent.horizontalCenter
        y: parent.height / 2.4
        anchors.leftMargin:  parent.width / 8
    }

    Rectangle{
        width: parent.width / 3
        height: parent.height / 5
        color: "steelblue"
        anchors.left: parent.horizontalCenter
        y: parent.height / 1.35
        anchors.leftMargin:  parent.width / 8
    }


    Text {
       id: text_n_FAZA_A
       font.pixelSize: parent.height / 15
       text: "Фаза A"
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       anchors.bottom: parent.verticalCenter
       anchors.bottomMargin: parent.height / 3.3
       anchors.leftMargin: parent.width / 4.2
    }

    Text {
       id: a_FAZA_A
       font.pixelSize: parent.height / 14
       text: "А"
       color: "lightgrey"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       anchors.bottom: parent.verticalCenter
       anchors.bottomMargin: parent.height / 5
       anchors.leftMargin: parent.width / 4.5
    }

    Text {
       id: txt_a_FAZA_A_block
       font.pixelSize: parent.height / 14
       text: txt_a_FAZA_A
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       anchors.bottom: parent.verticalCenter
       anchors.bottomMargin: parent.height / 5
       anchors.leftMargin: parent.width / 7
    }

    Text {
       id: v_FAZA_A
       font.pixelSize: parent.height / 14
       text: "B"
       color: "lightgrey"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       anchors.bottom: parent.verticalCenter
       anchors.bottomMargin: parent.height / 5
       anchors.leftMargin: parent.width / 2.45
    }

    Text {
       id: txt_v_FAZA_A_block
       font.pixelSize: parent.height / 14
       text: txt_v_FAZA_A
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       anchors.bottom: parent.verticalCenter
       anchors.bottomMargin: parent.height / 5
       anchors.leftMargin: parent.width / 3
    }

    Text {
       id: text_n_FAZA_B
       font.pixelSize: parent.height / 15
       text: "Фаза B"
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y: parent.height / 2.35
       anchors.leftMargin:  parent.width / 4.2
    }

    Text {
       id: a_FAZA_B
       font.pixelSize: parent.height / 14
       text: "А"
       color: "lightgrey"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y: parent.height / 1.9
       anchors.leftMargin: parent.width / 4.5
    }

    Text {
       id: txt_a_FAZA_B_block
       font.pixelSize: parent.height / 14
       text: txt_a_FAZA_B
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y: parent.height / 1.9
       anchors.leftMargin: parent.width / 7
    }

    Text {
       id: v_FAZA_B
       font.pixelSize: parent.height / 14
       text: "В"
       color: "lightgrey"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y: parent.height / 1.9
       anchors.leftMargin: parent.width / 2.45
    }

    Text {
       id: txt_v_FAZA_B_block
       font.pixelSize: parent.height / 14
       text: txt_v_FAZA_B
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y: parent.height / 1.9
       anchors.leftMargin: parent.width / 3
    }


    Text {
       id: text_n_FAZA_C
       font.pixelSize: parent.height / 15
       text: "Фаза С"
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y: parent.height / 1.33
       anchors.leftMargin:  parent.width / 4.2
    }

    Text {
       id: a_FAZA_C
       font.pixelSize: parent.height / 14
       text: "А"
       color: "lightgrey"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y:  parent.height / 1.17
       anchors.leftMargin: parent.width / 4.5
    }

    Text {
       id: txt_a_FAZA_C_block
       font.pixelSize: parent.height / 14
       text: txt_a_FAZA_C
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y:  parent.height / 1.17
       anchors.leftMargin: parent.width / 7
    }

    Text {
       id: v_FAZA_C
       font.pixelSize: parent.height / 14
       text: "В"
       color: "lightgrey"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y:  parent.height / 1.17
       anchors.leftMargin: parent.width / 2.45
    }

    Text {
       id: txt_v_FAZA_C_block
       font.pixelSize: parent.height / 14
       text: txt_v_FAZA_C
       color: "white"
       horizontalAlignment: Text.AlignRight
       anchors.left: parent.horizontalCenter
       y:  parent.height / 1.17
       anchors.leftMargin: parent.width / 3
    }

    Image {
        id: e_logo
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        source: "qrc:/new/images/images/electro.png"
        height: parent.height/5
        fillMode: Image.PreserveAspectFit
    }


    Connections{
         target: p_diselGen_tab
         onDataPanelChanged: { txt_a_FAZA_A = dataToPanel_A_FAZA_A; txt_v_FAZA_A = dataToPanel_V_FAZA_A;
                               txt_a_FAZA_B = dataToPanel_A_FAZA_B; txt_v_FAZA_B = dataToPanel_V_FAZA_B;
                               txt_a_FAZA_C = dataToPanel_A_FAZA_C; txt_v_FAZA_C = dataToPanel_V_FAZA_C
         }
}
}
