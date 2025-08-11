#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "includeFils.h"

#define maxTab      3

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_moveRightBtn_clicked();

    void on_moveRightBtn1_clicked();

    void on_moveLeftBtn1_clicked();

    void on_moveLeftBtn_clicked();

    void on_signalLeftBtn_clicked();

    void on_hazardBtn_clicked();

    void on_lightBtn_clicked();

    void on_warningBtn_clicked();

    void on_signalRightBtn_clicked();

    void on_airflowSlider_valueChanged(int value);

    void on_cabinSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_faceBtn_clicked();

    void on_feetBtn_clicked();

    void on_faceFeetBtn_clicked();

private:


 void updateWeather() ;

    Ui::MainWindow *ui;
    int m_curPos{} ;
};


#endif // MAINWINDOW_H





/*
    QQuickWidget *speedGauge = new QQuickWidget(this);
    speedGauge->setResizeMode(QQuickWidget::SizeRootObjectToView);
    speedGauge->setSource(QUrl("qrc:/SpeedGauge.qml"));
    speedGauge->setGeometry(350 , 250 , 500 , 380) ;
    speedGauge->rootObject()->setProperty("value", 205);

    QQuickWidget *rpmGauge = new QQuickWidget(this) ;
    rpmGauge->setResizeMode(QQuickWidget::SizeRootObjectToView);
    rpmGauge->setSource(QUrl("qrc:/RpmGauge.qml"));
    rpmGauge->setGeometry(615 , 620 , 220 , 170) ;
    rpmGauge->rootObject()->setProperty("value" , 4) ;


    QQuickWidget *fuelGauge = new QQuickWidget(this) ;
    fuelGauge->setResizeMode(QQuickWidget::SizeRootObjectToView);
    fuelGauge->setSource(QUrl("qrc:/FuelGauge.qml"));
    fuelGauge->setGeometry(375 , 620 , 220 , 170) ;
    fuelGauge->rootObject()->setProperty("value" , 7) ;
*/

