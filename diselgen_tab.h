#ifndef DISELGEN_TAB_H
#define DISELGEN_TAB_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QQuickWidget>
#include "modbus.h"

class diselGen_tab : public QWidget
{
    Q_OBJECT
public:
    explicit diselGen_tab(QWidget *parent = nullptr);
   // ~diselGen_tab();

    QQuickWidget *gaugeWidget_f1_B;
    QQuickWidget *gaugeWidget_f1_A;
    QQuickWidget *gaugeWidget_f2_B;
    QQuickWidget *gaugeWidget_f2_A;
    QQuickWidget *gaugeWidget_f3_B;
    QQuickWidget *gaugeWidget_f3_A;

    QQuickWidget *pressureWidget;
    QQuickWidget *powerWidget;

    QQuickWidget *gaugeWidget_bat;
    QQuickWidget *gaugeWidget_temp;

    QQuickWidget *panelDGA;

    QLabel *lineEdit_reg_29;
    QLabel *lineEdit_reg_61;
    QLabel *lineEdit_reg_63;
    QLabel *lineEdit_reg_65;
    QLabel *lineEdit_reg_68;
    QLabel *lineEdit_reg_71;

    QCheckBox *chk_KM1;
    QCheckBox *chk_KM2;
    QCheckBox *chk_DGU;

    QLabel *lb_rejim_upr_value;
    QLabel *lb_rejim_epu_value;

    QCheckBox *checkBox_reg_119_0;
    QCheckBox *checkBox_reg_119_3;
    QCheckBox *checkBox_reg_119_4;
    QCheckBox *checkBox_reg_119_7;

    QCheckBox *checkBox_reg_111_0;
    QCheckBox *checkBox_reg_111_1;
    QCheckBox *checkBox_reg_111_2;
    QCheckBox *checkBox_reg_111_4;
    QCheckBox *checkBox_reg_111_6;
    QCheckBox *checkBox_reg_111_8;
    QCheckBox *checkBox_reg_111_13;
    QCheckBox *checkBox_reg_111_15;
    QCheckBox *checkBox_reg_112_0;
    QCheckBox *checkBox_reg_112_1;
    QCheckBox *checkBox_reg_112_2;
    QCheckBox *checkBox_reg_112_3;
    QCheckBox *checkBox_reg_112_4;
    QCheckBox *checkBox_reg_112_7;
    QCheckBox *checkBox_reg_112_9;
    QCheckBox *checkBox_reg_112_10;
    QCheckBox *checkBox_reg_112_11;
    QCheckBox *checkBox_reg_112_12;
    QCheckBox *checkBox_reg_112_14;
    QCheckBox *checkBox_reg_112_15;
    QCheckBox *checkBox_reg_113_1;
    QCheckBox *checkBox_reg_114_3;
    QCheckBox *checkBox_reg_113_2;
    QCheckBox *checkBox_reg_114_4;
    QCheckBox *checkBox_reg_113_3;
    QCheckBox *checkBox_reg_114_5;
    QCheckBox *checkBox_reg_115_0;

    ModbusNetwork   *modnet_DGA;
    //QTimer          *updateTimer_DGA;
    QTimer          *updateReg_DGA;

    //QComboBox *comboBox_DGA;
    QPushButton *pushButton_connect_DGA;

    int ports_count;

    //void findPort_DGA();
    void onConnectionRelease_DGA();
    //void updatePortsList_DGA();
    void updateRegisters_DGA();

    QByteArray bitsToBytes(QBitArray bits);
    QByteArray convertFloatToValues(float f);
    float convertArrayToFloat(QByteArray array_bytes, quint8 position);

    void setDataToPressure(double newValPressure);
    void setDataToPower(double newValPower);
    void setDataToTempGauge(double newValTempGauge, QString newValueToTempGauge);
    void setDataToBatteryGauge(double newValBatteryGauge, QString newValueToBatteryGauge);
    void setDataToPanel(QString newValPanel_A_FAZA_A, QString newValPanel_V_FAZA_A,
                        QString newValPanel_A_FAZA_B, QString newValPanel_V_FAZA_B,
                        QString newValPanel_A_FAZA_C, QString newValPanel_V_FAZA_C);

    void update();
    void send(quint8 reg_first, quint8 count);

    void onApplicationQuit_DGA();

     QByteArray *otvet_DGA;

signals:
    void dataPressureChanged(double dataToPressure);//давление
    void dataPowerChanged(double valueToPower);//обороты
    void dataTempGaugeChanged(double dataToTempGauge, QString valueToTempGauge);
    void dataBatteryGaugeChanged(double dataToBatteryGauge, QString valueToBatteryGauge);
    void dataPanelChanged(QString dataToPanel_A_FAZA_A, QString dataToPanel_V_FAZA_A,
                          QString dataToPanel_A_FAZA_B, QString dataToPanel_V_FAZA_B,
                          QString dataToPanel_A_FAZA_C, QString dataToPanel_V_FAZA_C);

private slots:
    void up(QByteArray arr);

private slots:
    void on_pushButton_clicked();
private:
    QHBoxLayout *TABlayout;
};

extern diselGen_tab *p_diselGen_tab;

#endif // DISELGEN_TAB_H
