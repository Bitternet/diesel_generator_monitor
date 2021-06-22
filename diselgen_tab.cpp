#include "diselgen_tab.h"
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include <QSerialPortInfo>

const QString res_off = ":/new/images/res/icons/off.png";
const QString res_on = ":/new/images/res/icons/on.png";

enum
{
    PORT_LIST_UPDATE_INTERVAL = 100
};

diselGen_tab::diselGen_tab(QWidget *parent) : QWidget(parent)
{
    QString PathIconsCheckBox = "QCheckBox::indicator { width:70px; height: 70px; } QCheckBox::indicator::checked {image: url("+res_on+");}"
                                "QCheckBox::indicator::unchecked {image: url("+res_off+");}";

     QVBoxLayout *vertLayout_diselGen_tab = new QVBoxLayout;
     setLayout(vertLayout_diselGen_tab);

     QTabWidget *tabWidget_dga = new QTabWidget();
     QVBoxLayout *vertLayout_dga = new QVBoxLayout;
     tabWidget_dga->setLayout(vertLayout_dga);
     vertLayout_diselGen_tab->addWidget(tabWidget_dga);

     QTabWidget *tab_panel = new QTabWidget();
     QVBoxLayout *vertLayout_panel= new QVBoxLayout;
     tab_panel->setLayout(vertLayout_panel);
     QTabWidget *tab_mes = new QTabWidget();
     QVBoxLayout *vertLayout_mes = new QVBoxLayout;
     tab_mes->setLayout(vertLayout_mes);

     tabWidget_dga->addTab(tab_panel,"Панель показателей ДГА");
     tabWidget_dga->addTab(tab_mes,"Аварии и предупреждения");

     QGridLayout *gridLayout = new QGridLayout;

     QLabel *lb_titul = new QLabel("Дизельный электрогенератор ДГА");
     lb_titul->setMinimumHeight(40);
     lb_titul->setMaximumHeight(40);
     lb_titul->setStyleSheet("font: bold; background-color: dimgrey; color: white; font-size: 18px;");
     lb_titul->setAlignment(Qt::AlignHCenter);
     vertLayout_panel->addWidget(lb_titul);

     QGridLayout *gridLayout_widgets = new QGridLayout;
     QGridLayout *gridLayout_widgets_bottom = new QGridLayout;
     QGridLayout *gridLayout_tab_parametr = new QGridLayout;


/*
     QLabel *lb_p1 = new QLabel("Ток генератора фаза A");
     lb_p1->setStyleSheet("font: bold;");
     lb_p1->setMinimumHeight(40);
     lb_p1->setMaximumHeight(40);
     lb_p1->setAlignment(Qt::AlignHCenter);
     gridLayout_widgets->addWidget(lb_p1, 0,0);

     gaugeWidget_f1_A = new QQuickWidget();
     gaugeWidget_f1_A->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     gaugeWidget_f1_A->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_f1_A->setSource(QUrl("qrc:/new/qml/qml/gauge.qml"));
     QObject *object_f1_A = gaugeWidget_f1_A->rootObject();
     object_f1_A->setProperty("textChange","A");
     object_f1_A->setProperty("textValue","-");
     object_f1_A->setProperty("textMin","150А");
     object_f1_A->setProperty("textMax","200А");
     gridLayout_widgets->addWidget(gaugeWidget_f1_A,1,0);

     QLabel *lb_p2 = new QLabel("Линейное напряжение генератора фазы AB");
     lb_p2->setStyleSheet("font: bold;");
     lb_p2->setMinimumHeight(40);
     lb_p2->setMaximumHeight(40);
     lb_p2->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets->addWidget(lb_p2, 2, 0);

     gaugeWidget_f1_B = new QQuickWidget();
     gaugeWidget_f1_B->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     gaugeWidget_f1_B->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_f1_B->setSource(QUrl("qrc:/new/qml/qml/gauge.qml"));
     QObject *object_f1_B = gaugeWidget_f1_B->rootObject();
     object_f1_B->setProperty("textChange","B");
     object_f1_B->setProperty("textValue","-");
     object_f1_B->setProperty("textMin","210В");
     object_f1_B->setProperty("textMax","250В");
     gridLayout_widgets->addWidget(gaugeWidget_f1_B,3,0);

     QLabel *lb_p3 = new QLabel("Ток генератора фаза В");
     lb_p3->setStyleSheet("font: bold;");
     lb_p3->setMinimumHeight(40);
     lb_p3->setMaximumHeight(40);
     lb_p3->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets->addWidget(lb_p3, 0, 1);

     gaugeWidget_f2_A = new QQuickWidget();
     gaugeWidget_f2_A->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     gaugeWidget_f2_A->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_f2_A->setSource(QUrl("qrc:/new/qml/qml/gauge.qml"));
     QObject *object_f2_A = gaugeWidget_f2_A->rootObject();
     object_f2_A->setProperty("textChange","A");
     object_f2_A->setProperty("textValue","-");
     object_f2_A->setProperty("textMin","150А");
     object_f2_A->setProperty("textMax","200А");
     gridLayout_widgets->addWidget(gaugeWidget_f2_A,1,1);

     QLabel *lb_p4 = new QLabel("Линейное напряжение генератора фазы BC");
     lb_p4->setStyleSheet("font: bold;");
     lb_p4->setMinimumHeight(40);
     lb_p4->setMaximumHeight(40);
     lb_p4->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets->addWidget(lb_p4, 0, 2);

     gaugeWidget_f2_B = new QQuickWidget();
     gaugeWidget_f2_B->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     gaugeWidget_f2_B->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_f2_B->setSource(QUrl("qrc:/new/qml/qml/gauge.qml"));
     QObject *object_f2_B = gaugeWidget_f2_B->rootObject();
     object_f2_B->setProperty("textChange","B");
     object_f2_B->setProperty("textValue","-");
     object_f2_B->setProperty("textMin","210В");
     object_f2_B->setProperty("textMax","250В");
     gridLayout_widgets->addWidget(gaugeWidget_f2_B, 1, 2);

     QLabel *lb_p5 = new QLabel("Ток генератора фаза С");
     lb_p5->setStyleSheet("font: bold;");
     lb_p5->setMinimumHeight(40);
     lb_p5->setMaximumHeight(40);
     lb_p5->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets->addWidget(lb_p5, 0, 3);

     gaugeWidget_f3_A = new QQuickWidget();
     gaugeWidget_f3_A->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     gaugeWidget_f3_A->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_f3_A->setSource(QUrl("qrc:/new/qml/qml/gauge.qml"));
     QObject *object_f3_A = gaugeWidget_f3_A->rootObject();
     object_f3_A->setProperty("textChange","A");
     object_f3_A->setProperty("textValue","-");
     object_f3_A->setProperty("textMin","150А");
     object_f3_A->setProperty("textMax","200А");
     gridLayout_widgets->addWidget(gaugeWidget_f3_A, 1, 3);

     QLabel *lb_p6 = new QLabel("Линейное напряжение генератора фазы CA");
     lb_p6->setStyleSheet("font: bold;");
     lb_p6->setMinimumHeight(40);
     lb_p6->setMaximumHeight(40);
     lb_p6->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets->addWidget(lb_p6, 2, 3);

     gaugeWidget_f3_B = new QQuickWidget();
     gaugeWidget_f3_B->engine()->rootContext()->setContextProperty("diselGen_tab", this);
     gaugeWidget_f3_B->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_f3_B->setSource(QUrl("qrc:/new/qml/qml/gauge.qml"));
     QObject *object_f3_B = gaugeWidget_f3_B->rootObject();
     object_f3_B->setProperty("textChange","B");
     object_f3_B->setProperty("textValue","-");
     object_f3_B->setProperty("textMin","210В");
     object_f3_B->setProperty("textMax","250В");
     gridLayout_widgets->addWidget(gaugeWidget_f3_B,3,3);
*/
     QLabel *lb_dv1 = new QLabel("Давление масла");
     lb_dv1->setStyleSheet("font: bold;");
     lb_dv1->setMinimumHeight(40);
     lb_dv1->setMaximumHeight(40);
     lb_dv1->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets_bottom->addWidget(lb_dv1, 0, 0);

     pressureWidget = new QQuickWidget();
     pressureWidget->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     pressureWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
     pressureWidget->setSource(QUrl("qrc:/new/qml/qml/pressure.qml"));
     QObject *object_pressure = pressureWidget->rootObject();
     object_pressure->setProperty("maxValue",10);
     gridLayout_widgets_bottom->addWidget(pressureWidget, 1, 0, 6, 1);

     QLabel *lb_dv2 = new QLabel("Напряжение аккумулятора");
     lb_dv2->setStyleSheet("font: bold;");
     lb_dv2->setMinimumHeight(40);
     lb_dv2->setMaximumHeight(40);
     lb_dv2->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets_bottom->addWidget(lb_dv2, 3, 1);

     gaugeWidget_bat = new QQuickWidget();
     gaugeWidget_bat->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     gaugeWidget_bat->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_bat->setSource(QUrl("qrc:/new/qml/qml/gaugeBattery.qml"));
     QObject *object_bat =  gaugeWidget_bat->rootObject();
     object_bat->setProperty("icoChange","qrc:/new/images/images/battery.png");
     object_bat->setProperty("textValue","-");
     object_bat->setProperty("textMin","20В");
     object_bat->setProperty("textMax","40В");
     gridLayout_widgets_bottom->addWidget(gaugeWidget_bat, 4, 1, 3, 1);

     QLabel *lb_dv3 = new QLabel("Температура");
     lb_dv3->setStyleSheet("font: bold;");
     lb_dv3->setMinimumHeight(40);
     lb_dv3->setMaximumHeight(40);
     lb_dv3->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets_bottom->addWidget(lb_dv3, 3, 2);

     gaugeWidget_temp = new QQuickWidget();
     gaugeWidget_temp->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     gaugeWidget_temp->setResizeMode(QQuickWidget::SizeRootObjectToView);
     gaugeWidget_temp->setSource(QUrl("qrc:/new/qml/qml/gaugeTemp.qml"));
     QObject *object_temp =  gaugeWidget_temp->rootObject();
     object_temp->setProperty("icoChange","qrc:/new/images/images/temperature.png");
     object_temp->setProperty("minWarning","transparent");
     object_temp->setProperty("textValue","-");
     object_temp->setProperty("textMin","0°C");
     object_temp->setProperty("textMax","100°C");
     gridLayout_widgets_bottom->addWidget(gaugeWidget_temp, 4, 2, 3, 1);

     QLabel *lb_dv4 = new QLabel("Количество оборотов");
     lb_dv4->setStyleSheet("font: bold;");
     lb_dv4->setMinimumHeight(40);
     lb_dv4->setMaximumHeight(40);
     lb_dv4->setAlignment(Qt::AlignHCenter);

     gridLayout_widgets_bottom->addWidget(lb_dv4, 0, 3);

     powerWidget = new QQuickWidget();
     powerWidget->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     powerWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
     powerWidget->setSource(QUrl("qrc:/new/qml/qml/tachometer.qml"));
     QObject *object_power =  powerWidget->rootObject();
     object_power->setProperty("maxValue",18);
     object_power->setProperty("textTACH","x1000");
     gridLayout_widgets_bottom->addWidget(powerWidget, 1, 3, 6, 1);

     panelDGA = new QQuickWidget();
     panelDGA->engine()->rootContext()->setContextProperty("p_diselGen_tab", this);
     panelDGA->setResizeMode(QQuickWidget::SizeRootObjectToView);
     panelDGA->setSource(QUrl("qrc:/new/qml/qml/panelDGA.qml"));
     //panelDGA->setMinimumHeight(400);
     //panelDGA->setMinimumWidth(600);
     QObject *object_DGA =  powerWidget->rootObject();
     gridLayout_widgets->addWidget(panelDGA, 0, 1, 2, 2);

     gridLayout_widgets->addLayout(gridLayout, 0, 0, 2, 2);

     QLabel *lb_rejim_epudga = new QLabel("Режим управления ЭПУДГА: ");
     lb_rejim_epudga->setMinimumHeight(40);
     lb_rejim_epudga->setMaximumHeight(40);
     gridLayout->addWidget(lb_rejim_epudga, 1, 0);
     lb_rejim_upr_value = new QLabel("Нет данных");
     lb_rejim_upr_value->setStyleSheet("background-color: white; border-style: solid; border-width: 2px; border-color: green; border-radius: 5px; font-size: 15px;");
     lb_rejim_upr_value->setAlignment(Qt::AlignHCenter);
     gridLayout->addWidget(lb_rejim_upr_value , 1, 1);

     QLabel *lb_rejim_rabot = new QLabel("Режим работы:");
     lb_rejim_rabot->setMinimumHeight(40);
     lb_rejim_rabot->setMaximumHeight(40);
     gridLayout->addWidget(lb_rejim_rabot, 2, 0);
     lb_rejim_epu_value = new QLabel("Нет данных");
     lb_rejim_epu_value->setStyleSheet("background-color: white; border-style: solid; border-width: 2px; border-color: green; border-radius: 5px;");
     lb_rejim_epu_value->setAlignment(Qt::AlignHCenter);
     gridLayout->addWidget(lb_rejim_epu_value , 2, 1);

     QLabel *lb_gz_gen = new QLabel("Частота генератора:");
     lb_gz_gen->setMinimumHeight(40);
     lb_gz_gen->setMaximumHeight(40);
     gridLayout_tab_parametr->addWidget(lb_gz_gen, 0, 0);
     lineEdit_reg_29 = new QLabel("- Гц");
     gridLayout_tab_parametr->addWidget(lineEdit_reg_29, 0, 1);
     lineEdit_reg_29->setAlignment(Qt::AlignHCenter);
     lineEdit_reg_29->setStyleSheet("font: bold");

     QLabel *lb_a = new QLabel("Активная мощность:");
     lb_a->setMinimumHeight(40);
     lb_a->setMaximumHeight(40);
     gridLayout_tab_parametr->addWidget(lb_a, 0, 2);
     lineEdit_reg_61  = new QLabel("- кВт");
     gridLayout_tab_parametr->addWidget(lineEdit_reg_61, 0, 3);
     lineEdit_reg_61->setAlignment(Qt::AlignHCenter);
     lineEdit_reg_61->setStyleSheet("font: bold");

     QLabel *lb_r = new QLabel("Реактивная мощность:");
     lb_r->setMinimumHeight(40);
     lb_r->setMaximumHeight(40);
     gridLayout_tab_parametr->addWidget(lb_r, 1, 2);
     lineEdit_reg_63  = new QLabel("- кВАр");
     gridLayout_tab_parametr->addWidget(lineEdit_reg_63, 1, 3);
     lineEdit_reg_63->setAlignment(Qt::AlignHCenter);
     lineEdit_reg_63->setStyleSheet("font: bold");

     QLabel *lb_pm = new QLabel("Полная мощность:");
     lb_pm->setMinimumHeight(40);
     lb_pm->setMaximumHeight(40);
     gridLayout_tab_parametr->addWidget(lb_pm, 2, 2);
     lineEdit_reg_65  = new QLabel("- кВА");
     gridLayout_tab_parametr->addWidget(lineEdit_reg_65, 2, 3);
     lineEdit_reg_65->setAlignment(Qt::AlignHCenter);
     lineEdit_reg_65->setStyleSheet("font: bold");

     QLabel *lb_k = new QLabel("Коэффициент мощности:");
     lb_k->setMinimumHeight(40);
     lb_k->setMaximumHeight(40);
     gridLayout_tab_parametr->addWidget(lb_k, 1, 0);
     lineEdit_reg_68  = new QLabel("- cosф");
     gridLayout_tab_parametr->addWidget(lineEdit_reg_68, 1, 1);
     lineEdit_reg_68->setAlignment(Qt::AlignHCenter);
     lineEdit_reg_68->setStyleSheet("font: bold");

     QLabel *lb_v = new QLabel("Время работы двигателя:");
     lb_v->setMinimumHeight(40);
     lb_v->setMaximumHeight(40);
     gridLayout_tab_parametr->addWidget(lb_v, 2, 0);
     lineEdit_reg_71 = new QLabel("- ч");
     gridLayout_tab_parametr->addWidget(lineEdit_reg_71, 2, 1);
     lineEdit_reg_71->setAlignment(Qt::AlignHCenter);
     lineEdit_reg_71->setStyleSheet("font: bold");

     QLabel *lb_KM1 = new QLabel("КМ1 ЩАВР СЕТИ");
     gridLayout->addWidget(lb_KM1, 3, 0);
     chk_KM1 = new QCheckBox();
     chk_KM1->setMinimumHeight(40);
     chk_KM1->setMaximumHeight(40);
     chk_KM1->setStyleSheet(PathIconsCheckBox);
     chk_KM1->setAttribute(Qt::WA_TransparentForMouseEvents);
     chk_KM1->setFocusPolicy(Qt::NoFocus);

     gridLayout->addWidget(chk_KM1, 3, 1);

     QLabel *lb_KM2 = new QLabel("КМ2 ЩАВР СЕТИ");
     gridLayout->addWidget(lb_KM2, 4, 0);
     chk_KM2 = new QCheckBox();
     chk_KM2->setMinimumHeight(40);
     chk_KM2->setMaximumHeight(40);
     chk_KM2->setStyleSheet(PathIconsCheckBox);
     chk_KM2->setAttribute(Qt::WA_TransparentForMouseEvents);
     chk_KM2->setFocusPolicy(Qt::NoFocus);
     gridLayout->addWidget(chk_KM2, 4, 1);

     QLabel *lb_DGU = new QLabel("КМ2 ЩАВР ДГУ");
     gridLayout->addWidget(lb_DGU, 5, 0);
     chk_DGU = new QCheckBox();
     chk_DGU->setMinimumHeight(40);
     chk_DGU->setMaximumHeight(40);
     chk_DGU->setStyleSheet(PathIconsCheckBox);
     chk_DGU->setAttribute(Qt::WA_TransparentForMouseEvents);
     chk_DGU->setFocusPolicy(Qt::NoFocus);
     gridLayout->addWidget(chk_DGU, 5, 1);

     QLabel *lb_buf = new QLabel();
     lb_buf->setMinimumHeight(25);
     gridLayout->addWidget(lb_buf, 7, 0, 1, 5);

     QGridLayout *gridLayout_problem = new QGridLayout();
     vertLayout_mes->addLayout(gridLayout_problem);

     QLabel *lb_titul_ob_st = new QLabel("Обобщенный статус аварий и предупреждений");
     lb_titul_ob_st->setStyleSheet("background-color: dimgrey; color: white; font: bold;");
     lb_titul_ob_st->setMinimumHeight(40);
     lb_titul_ob_st->setMaximumHeight(40);
     lb_titul_ob_st->setAlignment(Qt::AlignHCenter);
     gridLayout_problem->addWidget(lb_titul_ob_st, 0, 0, 1, 2);
     checkBox_reg_119_0 = new QCheckBox("Есть активные предупреждения");
     checkBox_reg_119_0->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_119_0->setMinimumHeight(28);
     checkBox_reg_119_0->setMaximumHeight(40);
     checkBox_reg_119_0->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_119_0->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_119_0, 1, 0);
     checkBox_reg_119_3 = new QCheckBox("Есть активные аварии");
     checkBox_reg_119_3->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_119_3->setMinimumHeight(28);
     checkBox_reg_119_3->setMaximumHeight(40);
     checkBox_reg_119_3->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_119_3->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_119_3, 2, 0);
     checkBox_reg_119_4 = new QCheckBox("Есть неподтвержденные предупреждения");
     checkBox_reg_119_4->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_119_4->setMinimumHeight(28);
     checkBox_reg_119_4->setMaximumHeight(40);
     checkBox_reg_119_4->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_119_4->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_119_4, 1, 1);
     checkBox_reg_119_7 = new QCheckBox("Есть неподтвержденные аварии");
     checkBox_reg_119_7->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_119_7->setMinimumHeight(28);
     checkBox_reg_119_7->setMaximumHeight(40);
     checkBox_reg_119_7->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_119_7->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_119_7, 2, 1);

     QLabel *lb_titul_st = new QLabel("Cтатус аварий и предупреждений");
     lb_titul_st->setStyleSheet("background-color: dimgrey; color: white; font: bold;");
     lb_titul_st->setMinimumHeight(40);
     lb_titul_st->setMaximumHeight(40);
     lb_titul_st->setAlignment(Qt::AlignHCenter);
     gridLayout_problem->addWidget(lb_titul_st, 3, 0, 1, 2);

     checkBox_reg_111_0 = new QCheckBox("Неудачный старт");
     checkBox_reg_111_0->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_0->setMinimumHeight(28);
     checkBox_reg_111_0->setMaximumHeight(40);
     checkBox_reg_111_0->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_0->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_0, 4, 0);
     checkBox_reg_111_1 = new QCheckBox("Неуспешная остановка");
     checkBox_reg_111_1->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_1->setMinimumHeight(28);
     checkBox_reg_111_1->setMaximumHeight(40);
     checkBox_reg_111_1->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_1->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_1, 4, 1);
     checkBox_reg_111_2 = new QCheckBox("Неисправность зарядного генератора");
     checkBox_reg_111_2->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_2->setMinimumHeight(28);
     checkBox_reg_111_2->setMaximumHeight(40);
     checkBox_reg_111_2->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_2->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_2, 5, 0);
     checkBox_reg_111_4 = new QCheckBox("Работа вразнос");
     checkBox_reg_111_4->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_4->setMinimumHeight(28);
     checkBox_reg_111_4->setMaximumHeight(40);
     checkBox_reg_111_4->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_4->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_4, 5, 1);
     checkBox_reg_111_6 = new QCheckBox("Аварийный уровень топлива");
     checkBox_reg_111_6->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_6->setMinimumHeight(28);
     checkBox_reg_111_6->setMaximumHeight(40);
     checkBox_reg_111_6->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_6->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_6, 6, 0);
     checkBox_reg_111_8 = new QCheckBox("Топлива на 2 часа работы");
     checkBox_reg_111_8->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_8->setMinimumHeight(28);
     checkBox_reg_111_8->setMaximumHeight(40);
     checkBox_reg_111_8->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_8->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_8, 6, 1);
     checkBox_reg_111_13 = new QCheckBox("Предаварийная температура охлаждающей жидкости ");
     checkBox_reg_111_13->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_13->setMinimumHeight(28);
     checkBox_reg_111_13->setMaximumHeight(40);
     checkBox_reg_111_13->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_13->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_13, 7, 0);
     checkBox_reg_111_15 = new QCheckBox("Высокая температура охлаждающей жидкости ");
     checkBox_reg_111_15->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_111_15->setMinimumHeight(28);
     checkBox_reg_111_15->setMaximumHeight(40);
     checkBox_reg_111_15->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_111_15->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_111_15, 7, 1);

     checkBox_reg_112_0 = new QCheckBox("Аварийное давление масла");
     checkBox_reg_112_0->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_0->setMinimumHeight(28);
     checkBox_reg_112_0->setMaximumHeight(40);
     checkBox_reg_112_0->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_0->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_0, 8, 0);
     checkBox_reg_112_1 = new QCheckBox("Аварийное давление масла");
     checkBox_reg_112_1->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_1->setMinimumHeight(28);
     checkBox_reg_112_1->setMaximumHeight(40);
     checkBox_reg_112_1->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_1->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_1, 8, 1);
     checkBox_reg_112_2 = new QCheckBox("Низкое давление масла");
     checkBox_reg_112_2->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_2->setMinimumHeight(28);
     checkBox_reg_112_2->setMaximumHeight(40);
     checkBox_reg_112_2->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_2->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_2, 9, 0);
     checkBox_reg_112_3 = new QCheckBox("Низкое давление масла");
     checkBox_reg_112_3->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_3->setMinimumHeight(28);
     checkBox_reg_112_3->setMaximumHeight(40);
     checkBox_reg_112_3->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_3->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_3, 9, 1);
     checkBox_reg_112_4 = new QCheckBox("Максимальная мощность генератора");
     checkBox_reg_112_4->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_4->setMinimumHeight(28);
     checkBox_reg_112_4->setMaximumHeight(40);
     checkBox_reg_112_4->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_4->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_4, 10, 0);
     checkBox_reg_112_7 = new QCheckBox("Низкая температура охлаждающей жидкости");
     checkBox_reg_112_7->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_7->setMinimumHeight(28);
     checkBox_reg_112_7->setMaximumHeight(40);
     checkBox_reg_112_7->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_7->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_7, 10, 1);
     checkBox_reg_112_9 = new QCheckBox("Низкое напряжение генератора");
     checkBox_reg_112_9->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_9->setMinimumHeight(28);
     checkBox_reg_112_9->setMaximumHeight(40);
     checkBox_reg_112_9->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_9->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_9, 11, 0);
     checkBox_reg_112_10 = new QCheckBox("Низкая частота генератора");
     checkBox_reg_112_10->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_10->setMinimumHeight(28);
     checkBox_reg_112_10->setMaximumHeight(40);
     checkBox_reg_112_10->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_10->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_10, 11, 1);
     checkBox_reg_112_11 = new QCheckBox("Высокое напряжение генератора");
     checkBox_reg_112_11->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_11->setMinimumHeight(28);
     checkBox_reg_112_11->setMaximumHeight(40);
     checkBox_reg_112_11->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_11->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_11, 12, 0);
     checkBox_reg_112_12 = new QCheckBox("Высокая частота генератора");
     checkBox_reg_112_12->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_12->setMinimumHeight(28);
     checkBox_reg_112_12->setMaximumHeight(40);
     checkBox_reg_112_12->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_12->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_12, 12, 1);
     checkBox_reg_112_14 = new QCheckBox("Максимальный ток генератора");
     checkBox_reg_112_14->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_14->setMinimumHeight(28);
     checkBox_reg_112_14->setMaximumHeight(40);
     checkBox_reg_112_14->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_14->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_14, 13, 0);
     checkBox_reg_112_15 = new QCheckBox("Короткое замыкание (авария)");
     checkBox_reg_112_15->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_112_15->setMinimumHeight(28);
     checkBox_reg_112_15->setMaximumHeight(40);
     checkBox_reg_112_15->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_112_15->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_112_15, 13, 1);

     checkBox_reg_113_1 = new QCheckBox("Перекос напряжения генератора (авария)");
     checkBox_reg_113_1->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_113_1->setMinimumHeight(28);
     checkBox_reg_113_1->setMaximumHeight(40);
     checkBox_reg_113_1->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_113_1->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_113_1, 14, 0);
     checkBox_reg_113_2 = new QCheckBox("Перекос тока генератора (авария)");
     checkBox_reg_113_2->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_113_2->setMinimumHeight(28);
     checkBox_reg_113_2->setMaximumHeight(40);
     checkBox_reg_113_2->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_113_2->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_113_2, 15, 0);
     checkBox_reg_113_3 = new QCheckBox("Неверное чередование фаз (авария)");
     checkBox_reg_113_3->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_113_3->setMinimumHeight(28);
     checkBox_reg_113_3->setMaximumHeight(40);
     checkBox_reg_113_3->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_113_3->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_113_3, 16, 0);

     checkBox_reg_114_3 = new QCheckBox("Аварийная остановка");
     checkBox_reg_114_3->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_114_3->setMinimumHeight(28);
     checkBox_reg_114_3->setMaximumHeight(40);
     checkBox_reg_114_3->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_114_3->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_114_3, 14, 1);
     checkBox_reg_114_4 = new QCheckBox("Низкое напряжение аккумулятора (предупреждение)");
     checkBox_reg_114_4->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_114_4->setMinimumHeight(28);
     checkBox_reg_114_4->setMaximumHeight(40);
     checkBox_reg_114_4->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_114_4->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_114_4, 15, 1);
     checkBox_reg_114_5 = new QCheckBox("Высокое напряжение аккумулятора (предупреждение)");
     checkBox_reg_114_5->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_114_5->setMinimumHeight(28);
     checkBox_reg_114_5->setMaximumHeight(40);
     checkBox_reg_114_5->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_114_5->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_114_5, 16, 1);

     checkBox_reg_115_0 = new QCheckBox("Высокая температура охлаждающей жидкости");
     checkBox_reg_115_0->setStyleSheet(PathIconsCheckBox);
     checkBox_reg_115_0->setMinimumHeight(28);
     checkBox_reg_115_0->setMaximumHeight(40);
     checkBox_reg_115_0->setAttribute(Qt::WA_TransparentForMouseEvents);
     checkBox_reg_115_0->setFocusPolicy(Qt::NoFocus);
     gridLayout_problem->addWidget(checkBox_reg_115_0, 17, 0);
/*
     QLabel *lb_buf_pr = new QLabel();
     vertLayout_mes->addWidget(lb_buf_pr);
*/
     pushButton_connect_DGA = new QPushButton("Подключить");
     pushButton_connect_DGA->setMinimumHeight(40);
     pushButton_connect_DGA->setMinimumWidth(100);
     gridLayout->addWidget(pushButton_connect_DGA, 0, 0);
     connect(pushButton_connect_DGA, &QPushButton::released,
             this, &diselGen_tab::onConnectionRelease_DGA);

     //comboBox_DGA = new QComboBox();
     //comboBox_DGA->setMinimumHeight(40);
     //gridLayout->addWidget(comboBox_DGA,0,0);

     gridLayout_widgets_bottom->addLayout(gridLayout_tab_parametr, 0, 1, 3, 2);
     vertLayout_panel->addLayout(gridLayout_widgets);
     vertLayout_panel->addLayout(gridLayout_widgets_bottom);

     //findPort_DGA();

     modnet_DGA = new ModbusNetwork(this);

     connect(modnet_DGA, &ModbusNetwork::send_data_array, this, &diselGen_tab::up);

     //updateTimer_DGA = new QTimer(this);
     //updateTimer_DGA->setInterval(PORT_LIST_UPDATE_INTERVAL);

     updateReg_DGA = new QTimer(this);
     updateReg_DGA -> setInterval(1000);

     ports_count = 0;

     //connect(updateTimer_DGA, &QTimer::timeout,
             //this, &diselGen_tab::updatePortsList_DGA);

     connect(updateReg_DGA, &QTimer::timeout,
             this, &diselGen_tab::updateRegisters_DGA);

     //updateTimer_DGA -> start();
     updateReg_DGA -> start();

     pushButton_connect_DGA->setStyleSheet("background-color: green; color: white; font: bold;");

     otvet_DGA = new QByteArray();

     //comboBox_DGA->setFocus();
     //comboBox_DGA->setStyleSheet("font: bold");
}


void diselGen_tab::setDataToPressure(double newValPressure){
    emit dataPressureChanged(newValPressure);
}

void diselGen_tab::setDataToPower(double newValPower){
    emit dataPowerChanged(newValPower);
}

void diselGen_tab::setDataToTempGauge(double newValTempGauge, QString newValueToTempGauge){
    emit dataTempGaugeChanged(newValTempGauge,newValueToTempGauge);
}

void diselGen_tab::setDataToBatteryGauge(double newValBatteryGauge, QString newValueToBatteryGauge){
    emit dataBatteryGaugeChanged(newValBatteryGauge, newValueToBatteryGauge);
}

void diselGen_tab::setDataToPanel(QString newValPanel_A_FAZA_A, QString newValPanel_V_FAZA_A,
                                  QString newValPanel_A_FAZA_B, QString newValPanel_V_FAZA_B,
                                  QString newValPanel_A_FAZA_C, QString newValPanel_V_FAZA_C){
    emit dataPanelChanged(newValPanel_A_FAZA_A, newValPanel_V_FAZA_A,
                          newValPanel_A_FAZA_B, newValPanel_V_FAZA_B,
                          newValPanel_A_FAZA_C, newValPanel_V_FAZA_C);
}

void diselGen_tab::on_pushButton_clicked()
{
    double i = 0 + rand() % 10;
    setDataToPressure(i);

    double j = 0 + rand() % 15;
    setDataToPower(j);

    setDataToTempGauge(0.3, "30");
    setDataToBatteryGauge(0.8, "80");

    setDataToPanel("180", "230", "180", "230", "180", "230");
}
/*
void diselGen_tab::findPort_DGA()
{
    comboBox_DGA->clear();

        const auto infos = QSerialPortInfo::availablePorts();

        for (const QSerialPortInfo &info : infos)
        {
            QStringList list;
            list << info.portName();
            comboBox_DGA->addItem(list.first());
        }
 }

void diselGen_tab::updatePortsList_DGA()
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    if (ports.count() != ports_count)
    {
        ports_count = ports.count();
        comboBox_DGA->clear();

        for (int i = 0; i < ports_count; i++)
            comboBox_DGA->addItem(ports.at(i).portName());
    }
}
*/
QByteArray diselGen_tab::convertFloatToValues(float f)
{
    QByteArray array(reinterpret_cast<const char*>(&f), sizeof(f));
    return array;
}

float diselGen_tab::convertArrayToFloat(QByteArray array_bytes, quint8 position)
{
    QByteArray tmp;

    tmp[0] = array_bytes[position+1];
    tmp[1] = array_bytes[position];
    tmp[2] = array_bytes[position+3];
    tmp[3] = array_bytes[position+2];
    float f;
    if (tmp.size() >= sizeof(f))
    f = *reinterpret_cast<const float*>(tmp.data());
    return f;
}

void diselGen_tab::updateRegisters_DGA()
{
    if (modnet_DGA->isConnected())
    {
    send(7, 135);
    }
}

void diselGen_tab::send(quint8 reg_first, quint8 count)
{
    QByteArray w;
    quint8 dat[6];
    quint8 adress = 1;
    quint8 func = 4;

    w[0] = adress;
    w[1] = func;
    w[2] = hiByte(reg_first);
    w[3] = loByte(reg_first);
    w[4] = hiByte(count);
    w[5] = loByte(count);

    dat[0] = adress;
    dat[1] = func;
    dat[2] = hiByte(reg_first);
    dat[3] = loByte(reg_first);
    dat[4] = hiByte(count);
    dat[5] = loByte(count);

    quint16 ks = calcCRC16table(dat, 6);

    w[6] = hiByte(ks);
    w[7] = loByte(ks);
    modnet_DGA->sendData(w);
    qDebug() << w;
}

void diselGen_tab::update()
{
    updateRegisters_DGA();
}

void diselGen_tab::onConnectionRelease_DGA()
{
    if (modnet_DGA->isConnected())
    {
        modnet_DGA->closeConnection();

        pushButton_connect_DGA->setText("Подключить");
        pushButton_connect_DGA->setStyleSheet("background-color: green; color: white; font: bold");
        //logPring("Устройство отключено");
        qDebug()<<"Устройство отключено";
    }
    else
    {
        serial_config_t sp_config;

        sp_config.portName = "/dev/ttyMUE2";//comboBox_DGA->currentText();
        sp_config.baudrate = 9600;
        sp_config.dataBits = 8;
        sp_config.stopBits = 1;
        sp_config.parity = "None";

        modnet_DGA->init(sp_config);
        modnet_DGA->openConnection();

        pushButton_connect_DGA->setText("Отключить");
        pushButton_connect_DGA->setStyleSheet("background-color: red; color: white; font: bold");

        //logPring("Устройство подключено");
        qDebug()<<"Устройство подключено";
    }
    //comboBox_DGA->setFocus();
}

void diselGen_tab::onApplicationQuit_DGA()
{
    if (modnet_DGA->isConnected())
        modnet_DGA->closeConnection();

    QApplication::quit();
}

void diselGen_tab::up(QByteArray arr)
{
    otvet_DGA->append(arr);
    //qDebug()<<otvet->length();

    if(otvet_DGA->length() == 275)
    {
    QByteArray array = *otvet_DGA;

    setDataToPanel(QString::number(convertArrayToFloat(array,31)), QString::number(convertArrayToFloat(array, 3)),
                   QString::number(convertArrayToFloat(array,35)), QString::number(convertArrayToFloat(array, 7)),
                   QString::number(convertArrayToFloat(array,39)), QString::number(convertArrayToFloat(array, 11)));
/*
    ui->lineEdit_reg_7->setText(QString::number(convertArrayToFloat(array, 3)));
    ui->lineEdit_reg_9->setText(QString::number(convertArrayToFloat(array, 7)));
    ui->lineEdit_reg_11->setText(QString::number(convertArrayToFloat(array, 11)));

    ui->lineEdit_reg_21->setText(QString::number(convertArrayToFloat(array,31)));
    ui->lineEdit_reg_23->setText(QString::number(convertArrayToFloat(array,35)));
    ui->lineEdit_reg_25->setText(QString::number(convertArrayToFloat(array,39)));*/

    lineEdit_reg_29->setText(QString::number(convertArrayToFloat(array,47))+" Гц");

    lineEdit_reg_61->setText(QString::number(convertArrayToFloat(array,111))+" кВт");
    lineEdit_reg_63->setText(QString::number(convertArrayToFloat(array,115))+" кВАр");
    lineEdit_reg_65->setText(QString::number(convertArrayToFloat(array,119))+" кВА");
    lineEdit_reg_68->setText(QString::number(convertArrayToFloat(array,125))+" cosф");

    lineEdit_reg_71->setText(QString::number((quint16)(word(array[131],array[132])))+" ч");

    setDataToPressure((quint16)(word(array[143],array[144])));
    setDataToPower((quint16)(word(array[151],array[152]))/100);
    setDataToTempGauge(convertArrayToFloat(array,145)/100, QString::number(convertArrayToFloat(array,145)));
    setDataToBatteryGauge(((convertArrayToFloat(array,137)-20)/0.2)/100, QString::number(convertArrayToFloat(array,137)));

    quint16 reg_101 = (quint16)(word(array[191],array[192]));

    chk_KM1->setChecked(getBit(loByte(reg_101), 3));//КМ1
    chk_KM2->setChecked(getBit(loByte(reg_101), 4));//КМ2
    chk_DGU->setChecked(getBit(loByte(reg_101), 5));//ДГУ

    quint16 reg_121 = (quint16)(word(array[231],array[232]));//ЭПУДГА

    if(reg_121 == 0)
    lb_rejim_epu_value->setText("Отключено");
    else if(reg_121 == 1)
    lb_rejim_epu_value->setText("Ручной");
    else if(reg_121 == 2)
    lb_rejim_epu_value->setText("Автоматический");

    quint16 reg_133 = (quint16)(word(array[255],array[256]));//режим работы

    if(reg_133 == 0)
    lb_rejim_upr_value->setText("ДГА остановлен");
    else if(reg_133 == 1)
    lb_rejim_upr_value->setText("Запуск ДГА");
    else if(reg_133 == 6)
    lb_rejim_upr_value->setText("ДГА останавливается");
    else if(reg_133 == 16)
    lb_rejim_upr_value->setText("ДГА в режиме\nохлаждения");
    else if(reg_133 == 4)
    lb_rejim_upr_value->setText("ДГА работает");
    else if(reg_133 == 25)
    lb_rejim_upr_value->setText("ДГА работает");
    else if(reg_133 == 19)
    lb_rejim_upr_value->setText("ДГА работает на\nнагрузку");

    quint16 reg_119 = (quint16)(word(array[227],array[228]));//обобщенный статус

    checkBox_reg_119_0->setChecked(getBit(loByte(reg_119), 0));
    checkBox_reg_119_3->setChecked(getBit(loByte(reg_119), 3));
    checkBox_reg_119_4->setChecked(getBit(loByte(reg_119), 4));
    checkBox_reg_119_7->setChecked(getBit(loByte(reg_119), 7));

    quint16 reg_111 = (quint16)(word(array[211],array[212]));//статус

    checkBox_reg_111_0->setChecked(getBit(loByte(reg_111), 0));
    checkBox_reg_111_1->setChecked(getBit(loByte(reg_111), 1));
    checkBox_reg_111_2->setChecked(getBit(loByte(reg_111), 2));
    checkBox_reg_111_4->setChecked(getBit(loByte(reg_111), 4));
    checkBox_reg_111_6->setChecked(getBit(loByte(reg_111), 6));
    checkBox_reg_111_8->setChecked(getBit(hiByte(reg_111), 0));
    checkBox_reg_111_13->setChecked(getBit(hiByte(reg_111), 5));
    checkBox_reg_111_15->setChecked(getBit(hiByte(reg_111), 7));

    quint16 reg_112 = (quint16)(word(array[213],array[214]));

    checkBox_reg_112_0->setChecked(getBit(loByte(reg_112), 0));
    checkBox_reg_112_1->setChecked(getBit(loByte(reg_112), 1));
    checkBox_reg_112_2->setChecked(getBit(loByte(reg_112), 2));
    checkBox_reg_112_3->setChecked(getBit(loByte(reg_112), 3));
    checkBox_reg_112_4->setChecked(getBit(loByte(reg_112), 4));
    checkBox_reg_112_7->setChecked(getBit(loByte(reg_112), 7));
    checkBox_reg_112_9->setChecked(getBit(hiByte(reg_112), 1));
    checkBox_reg_112_10->setChecked(getBit(hiByte(reg_112), 2));
    checkBox_reg_112_11->setChecked(getBit(hiByte(reg_112), 3));
    checkBox_reg_112_12->setChecked(getBit(hiByte(reg_112), 4));
    checkBox_reg_112_14->setChecked(getBit(hiByte(reg_112), 6));
    checkBox_reg_112_15->setChecked(getBit(hiByte(reg_112), 7));

    quint16 reg_113 = (quint16)(word(array[215],array[216]));

    checkBox_reg_113_1->setChecked(getBit(loByte(reg_113), 1));
    checkBox_reg_113_2->setChecked(getBit(loByte(reg_113), 2));
    checkBox_reg_113_3->setChecked(getBit(loByte(reg_113), 3));

    quint16 reg_114 = (quint16)(word(array[217],array[218]));

    checkBox_reg_114_3->setChecked(getBit(loByte(reg_114), 3));
    checkBox_reg_114_4->setChecked(getBit(loByte(reg_114), 4));
    checkBox_reg_114_5->setChecked(getBit(loByte(reg_114), 5));

    quint16 reg_115 = (quint16)(word(array[219],array[220]));

    checkBox_reg_115_0->setChecked(getBit(loByte(reg_115), 0));


/*  ui->lineEdit_reg_74->setText(QString::number(convertArrayToFloat(array,137)));
    ui->lineEdit_reg_77->setText(QString::number((quint16)(word(array[143],array[144]))));//давление
    ui->lineEdit_reg_78->setText(QString::number(convertArrayToFloat(array,145)));//температура
    ui->lineEdit_reg_81->setText(QString::number((quint16)(word(array[151],array[152]))));//обороты

    quint16 reg_101 = (quint16)(word(array[191],array[192]));

    ui->checkBox_reg_101_3->setChecked(getBit(loByte(reg_101), 3));
    ui->checkBox_reg_101_4->setChecked(getBit(loByte(reg_101), 4));
    ui->checkBox_reg_101_5->setChecked(getBit(loByte(reg_101), 5));

    quint16 reg_111 = (quint16)(word(array[211],array[212]));

    ui->checkBox_reg_111_0->setChecked(getBit(loByte(reg_111), 0));
    ui->checkBox_reg_111_1->setChecked(getBit(loByte(reg_111), 1));
    ui->checkBox_reg_111_2->setChecked(getBit(loByte(reg_111), 2));
    ui->checkBox_reg_111_4->setChecked(getBit(loByte(reg_111), 4));
    ui->checkBox_reg_111_6->setChecked(getBit(loByte(reg_111), 6));
    ui->checkBox_reg_111_8->setChecked(getBit(hiByte(reg_111), 0));
    ui->checkBox_reg_111_13->setChecked(getBit(hiByte(reg_111), 5));
    ui->checkBox_reg_111_15->setChecked(getBit(hiByte(reg_111), 7));

    quint16 reg_112 = (quint16)(word(array[213],array[214]));

    ui->checkBox_reg_112_0->setChecked(getBit(loByte(reg_112), 0));
    ui->checkBox_reg_112_1->setChecked(getBit(loByte(reg_112), 1));
    ui->checkBox_reg_112_2->setChecked(getBit(loByte(reg_112), 2));
    ui->checkBox_reg_112_3->setChecked(getBit(loByte(reg_112), 3));
    ui->checkBox_reg_112_4->setChecked(getBit(loByte(reg_112), 4));
    ui->checkBox_reg_112_7->setChecked(getBit(loByte(reg_112), 7));
    ui->checkBox_reg_112_9->setChecked(getBit(hiByte(reg_112), 1));
    ui->checkBox_reg_112_10->setChecked(getBit(hiByte(reg_112), 2));
    ui->checkBox_reg_112_11->setChecked(getBit(hiByte(reg_112), 3));
    ui->checkBox_reg_112_12->setChecked(getBit(hiByte(reg_112), 4));
    ui->checkBox_reg_112_14->setChecked(getBit(hiByte(reg_112), 6));
    ui->checkBox_reg_112_15->setChecked(getBit(hiByte(reg_112), 7));

    quint16 reg_113 = (quint16)(word(array[215],array[216]));

    ui->checkBox_reg_113_1->setChecked(getBit(loByte(reg_113), 1));
    ui->checkBox_reg_113_2->setChecked(getBit(loByte(reg_113), 2));
    ui->checkBox_reg_113_3->setChecked(getBit(loByte(reg_113), 3));

    quint16 reg_114 = (quint16)(word(array[217],array[218]));

    ui->checkBox_reg_114_3->setChecked(getBit(loByte(reg_114), 3));
    ui->checkBox_reg_114_4->setChecked(getBit(loByte(reg_114), 4));
    ui->checkBox_reg_114_5->setChecked(getBit(loByte(reg_114), 5));

    quint16 reg_115 = (quint16)(word(array[219],array[220]));

    ui->checkBox_reg_115_0->setChecked(getBit(loByte(reg_115), 0));

    quint16 reg_119 = (quint16)(word(array[227],array[228]));

    ui->checkBox_reg_119_0->setChecked(getBit(loByte(reg_119), 0));
    ui->checkBox_reg_119_3->setChecked(getBit(loByte(reg_119), 3));
    ui->checkBox_reg_119_4->setChecked(getBit(loByte(reg_119), 4));
    ui->checkBox_reg_119_7->setChecked(getBit(loByte(reg_119), 7));

    quint16 reg_121 = (quint16)(word(array[231],array[232]));

    if(reg_121 == 0)
    ui->radioButton_reg_121_0->setChecked(true);
    else if(reg_121 == 1)
    ui->radioButton_reg_121_1->setChecked(true);
    else if(reg_121 == 2)
    ui->radioButton_reg_121_2->setChecked(true);

    quint16 reg_133 = (quint16)(word(array[255],array[256]));

    if(reg_133 == 0)
    ui->radioButton_reg_133_0->setChecked(true);
    else if(reg_133 == 1)
    ui->radioButton_reg_133_1->setChecked(true);
    else if(reg_133 == 6)
    ui->radioButton_reg_133_6 ->setChecked(true);
    else if(reg_133 == 16)
    ui->radioButton_reg_133_16 ->setChecked(true);
    else if(reg_133 == 4)
    ui->radioButton_reg_133_4 ->setChecked(true);
    else if(reg_133 == 25)
    ui->radioButton_reg_133_25 ->setChecked(true);
    else if(reg_133 == 19)
    ui->radioButton_reg_133_19 ->setChecked(true);
*/
    otvet_DGA->clear();
    }

}
