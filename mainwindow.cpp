#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Controller/cabintempcontrol.h"
#include "Controller/doorlockcontrol.h"
#include "Controller/fancontrol.h"
#include "Controller/gaugecontrol.h"
#include "Controller/lightcontrol.h"
#include "Controller/signallightcontrol.h"
#include "Controller/motortempcontrol.h"
#include "Controller/seatbeltcontrol.h"
#include "Controller/tripinfocontrol.h"
#include "Controller/warningcontrol.h"
#include "protobuf/tempupdate.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i{} ; i < maxTab ; i++) ui->tabWidget->tabBar()->setTabVisible(i , false) ;

    ui->tabWidget->setCurrentIndex(m_curPos) ;

    ui->fuelCon->setPixmap(QPixmap(":/Image/gas-pump.png")) ;
    ui->speed->setPixmap(QPixmap(":/Image/mileage.png")) ;
    ui->distance->setPixmap(QPixmap(":/Image/distance.png")) ;

    ui->speedGauge->setClearColor(Qt::transparent);
    ui->speedGauge->setAttribute(Qt::WA_TranslucentBackground);

    ui->rpmGauge->setClearColor(Qt::transparent) ;
    ui->rpmGauge->setAttribute(Qt::WA_TranslucentBackground);

    ui->fuelGuage->setClearColor(Qt::transparent) ;
    ui->fuelGuage->setAttribute(Qt::WA_TranslucentBackground);

    ui->faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
    ui->feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
    ui->faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;

    ui->carDoor->setPixmap(QPixmap(":/Image/car-door.png"));
    ui->lightBtn->setIcon(QIcon(":/Image/headlight.png")) ;
    ui->carSeatBelt->setPixmap(QPixmap(":/Image/seat-belt.png")) ;
    ui->signalLeftBtn->setIcon(QIcon(QPixmap(":/Image/left-arrow.png"))) ;
    ui->hazardBtn->setIcon(QIcon(QPixmap(":/Image/hazard (2).png"))) ;
    ui->signalRightBtn->setIcon(QIcon(QPixmap(":/Image/right-arrow (2).png"))) ;
    ui->warningBtn->setIcon(QIcon(":/Image/warning.png")) ;

}

MainWindow::~MainWindow()
{
    delete ui; ui = nullptr ;
}

void MainWindow::on_moveRightBtn_clicked()
{
    m_curPos = (m_curPos + 1) % maxTab ;
    if(m_curPos == 2) updateWeather() ;
    ui->tabWidget->setCurrentIndex(m_curPos) ;
}


void MainWindow::on_moveRightBtn1_clicked()
{
    this->on_moveRightBtn_clicked() ;
}


void MainWindow::on_moveLeftBtn1_clicked()
{
    this->on_moveLeftBtn_clicked() ;
}

void MainWindow::on_pushButton_clicked()
{
    on_moveLeftBtn_clicked() ;
}


void MainWindow::on_pushButton_2_clicked()
{
    on_moveRightBtn_clicked() ;
}


void MainWindow::on_moveLeftBtn_clicked()
{
    if(m_curPos == 0) m_curPos = maxTab - 1 ;
    else m_curPos -= 1 ;
    if(m_curPos == 2) updateWeather() ;
    ui->tabWidget->setCurrentIndex(m_curPos) ;
}

void MainWindow::on_signalLeftBtn_clicked()
{
    signalState state =  signalLightControl::leftArrowClicked() ;
    if(state == signalState::LEFTON){
        ui->signalLeftBtn->setIcon(QIcon(":/Image/left-arrow (1).png")) ;
    }
    else{
        ui->signalLeftBtn->setIcon(QIcon(":/Image/left-arrow.png")) ;
    }
    ui->hazardBtn->setIcon(QIcon(QPixmap(":/Image/hazard (2).png"))) ;
    ui->signalRightBtn->setIcon(QIcon(QPixmap(":/Image/right-arrow (2).png"))) ;
}


void MainWindow::on_hazardBtn_clicked()
{
    signalState state =  signalLightControl::hazardClicked() ;
    if(state == signalState::HAZARDON){
        ui->hazardBtn->setIcon(QIcon(":/Image/hazard .png")) ;
        ui->signalLeftBtn->setIcon(QIcon(":/Image/left-arrow (1).png")) ;
        ui->signalRightBtn->setIcon(QIcon(":/Image/right-arrow (3).png")) ;
    }
    else{
        ui->signalLeftBtn->setIcon(QIcon(QPixmap(":/Image/left-arrow.png"))) ;
        ui->hazardBtn->setIcon(QIcon(QPixmap(":/Image/hazard (2).png"))) ;
        ui->signalRightBtn->setIcon(QIcon(QPixmap(":/Image/right-arrow (2).png"))) ;
    }
}

void MainWindow::on_lightBtn_clicked()
{
    lightState state = lightControl::lightToggle() ;
    if(state == lightState::LIGHTON){
        ui->lightBtn->setIcon(QIcon(":/Image/headlight (2).png")) ;
    }
    else{
        ui->lightBtn->setIcon(QIcon(":/Image/headlight.png")) ;
    }
}


void MainWindow::on_warningBtn_clicked()
{

}


void MainWindow::on_signalRightBtn_clicked()
{
    signalState state =  signalLightControl::rightArrowClicked() ;
    if(state == signalState::RIGHTON){
        ui->signalRightBtn->setIcon(QIcon(":/Image/right-arrow (3).png")) ;
    }
    else{
        ui->signalRightBtn->setIcon(QIcon(":/Image/right-arrow (2).png")) ;
    }
    ui->hazardBtn->setIcon(QIcon(QPixmap(":/Image/hazard (2).png"))) ;
    ui->signalLeftBtn->setIcon(QIcon(":/Image/left-arrow.png")) ;
}

void MainWindow::on_airflowSlider_valueChanged(int value)
{
    ui->fanLcd->display(value) ;
    fanControl::setFanSpeed(value) ;
}


void MainWindow::on_cabinSlider_valueChanged(int value)
{
    ui->cabinLcd->display(value) ;
    cabinTempControl::setCabinTempControl(value) ;
}


void MainWindow::on_faceBtn_clicked()
{
    fanDirState state = fanControl::getFanDirection() ;
    if(state == fanDirState::FACEONLY){
        fanControl::setFanDirection(fanDirState::ALLOFF) ;
        ui->faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
    }
    else{
        fanControl::setFanDirection(fanDirState::FACEONLY) ;
        ui->faceBtn->setIcon(QIcon(":/Image/blowing (1).png")) ;
    }
    ui->feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
    ui->faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
}

void MainWindow::on_feetBtn_clicked()
{
    fanDirState state = fanControl::getFanDirection() ;
    if(state == fanDirState::FEETONLY){
        fanControl::setFanDirection(fanDirState::ALLOFF) ;
        ui->feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
    }
    else{
        fanControl::setFanDirection(fanDirState::FEETONLY) ;
        ui->feetBtn->setIcon(QIcon(":/Image/windscreen-air (2).png")) ;
    }
    ui->faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
    ui->faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
}

void MainWindow::on_faceFeetBtn_clicked()
{
    fanDirState state = fanControl::getFanDirection() ;
    if(state == fanDirState::FACEFEET){
        fanControl::setFanDirection(fanDirState::ALLOFF) ;
        ui->faceFeetBtn->setIcon(QIcon(":/Image/air-flow.png")) ;
    }
    else{
        fanControl::setFanDirection(fanDirState::FACEFEET) ;
        ui->faceFeetBtn->setIcon(QIcon(":/Image/air-flow (1).png")) ;
    }
    ui->faceBtn->setIcon(QIcon(":/Image/blowing.png")) ;
    ui->feetBtn->setIcon(QIcon(":/Image/windscreen-air.png")) ;
}


void MainWindow::updateWeather(){
  requestTemperatureOnce() ;
  ui->weather_Lcd->display(temp) ;
}
