#include "ghostleggenerator.h"
#include "ui_ghostleggenerator.h"
#include <iostream>

GhostLegGenerator::GhostLegGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GhostLegGenerator)
{
    ui->setupUi(this);
    stX = 20;
    stY = 5;
    endX = 750;
    endY = 5;
    yDiff = 50;
    btnIndex = 1;
    btnW = btnH = 30;
}

GhostLegGenerator::~GhostLegGenerator()
{
    delete ui;
}

void GhostLegGenerator::GenButton()
{
    QPushButton *qStBtn = CreateStartButton(btnIndex), *qEndBtn = CreateEndButton(btnIndex);
    qStBtn->setGeometry(stX, stY, btnW, btnH);
    qEndBtn->setGeometry(endX, endY, btnW, btnH);
    qStBtn->show();
    qEndBtn->show();
    stY += yDiff;
    endY += yDiff;
    qStartBtnList.append(qStBtn);
    qEndBtnList.append(qEndBtn);
    ++btnIndex;
}

QPushButton* GhostLegGenerator::CreateStartButton(int n)
{
    QPushButton *qTmpBtn = CreateButton(n);
    qTmpBtn->setAutoFillBackground(true);
    qTmpBtn->setStyleSheet("background-color: rgb(255, 144, 103); color: rgb(255, 255, 255)");
    qTmpBtn->update();
    return qTmpBtn;
}

QPushButton* GhostLegGenerator::CreateEndButton(int n)
{
    QPushButton *qTmpBtn = CreateButton(n);
    char curText = 'a'+n-1;
    qTmpBtn->setText(QString(curText));
    qTmpBtn->setAutoFillBackground(true);
    qTmpBtn->setStyleSheet("background-color: rgb(122, 255, 131); color: rgb(0, 0, 0)");
    qTmpBtn->update();
    return qTmpBtn;
}

QPushButton* GhostLegGenerator::CreateButton(int n)
{
    QPushButton *qTmpBtn = new QPushButton(QString::number(n), ui->subWidget);
    return qTmpBtn;
}

void GhostLegGenerator::on_runPB_clicked()
{
    reset();
    int btnNum = ui->numberLE->text().toInt();
    if(btnNum > 10 || btnNum <= 0) return;
    int unitH = 500/btnNum;
    btnH = unitH*0.5;
    if(btnH > 30) btnH = 30;
    btnH -= 5;
    yDiff = unitH - btnH;
    for(int i = 0; i < btnNum; ++i)
        GenButton();
}

void GhostLegGenerator::reset()
{
    for(QPushButton* qTmpPB:qStartBtnList){
        delete qTmpPB;
    }
    for(QPushButton* qTmpPB:qEndBtnList){
        delete qTmpPB;
    }
    qStartBtnList.clear();
    qEndBtnList.clear();
    btnIndex = 1;
    stY = 5;
    endY = 5;
}
