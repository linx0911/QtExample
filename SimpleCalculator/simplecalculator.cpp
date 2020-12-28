#include "simplecalculator.h"
#include "ui_simplecalculator.h"
#include <iostream>

using namespace std;

SimpleCalculator::SimpleCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);
    curNum = 0;
    nextNum = 0;
    state = true;
    opt = 1;
}

SimpleCalculator::~SimpleCalculator()
{
    delete ui;
}

void SimpleCalculator::SetResult(QString str, int fontSize)
{
    ui->resultLbl->setText(str);
    QFont tmpFont = ui->resultLbl->font();
    tmpFont.setPixelSize(fontSize);
    ui->resultLbl->setFont(tmpFont);
}

void SimpleCalculator::SetNumber(int n)
{
    if(state){
        curNum = 10 * curNum + n;
        SetResult(QString::number(curNum));
    }
    else{
        nextNum = 10 * nextNum + n;
        SetResult(QString::number(nextNum));
    }
}

void SimpleCalculator::ComputeEng()
{
    switch (opt) {
        case 1:
            curNum += nextNum;
            break;
        case 2:
            curNum -= nextNum;
            break;
        case 3:
            curNum *= nextNum;
            break;
        case 4:
            if(nextNum == 0){
                SetResult("Can't divide Zero", 50);
                curNum = 0;
                nextNum = 0;
                return;
            }
            curNum /= nextNum;
    }
    SetResult(QString::number(curNum));
}

void SimpleCalculator::OpreatorStep()
{
    if(!state) ComputeEng();
    else SetResult(QString::number(curNum));
    state = false;
    nextNum = 0;
}

void SimpleCalculator::on_zeroPB_clicked()
{
    SetNumber(0);
}


void SimpleCalculator::on_onePB_clicked()
{
    SetNumber(1);
}

void SimpleCalculator::on_twoPB_clicked()
{
    SetNumber(2);
}

void SimpleCalculator::on_threePB_clicked()
{
    SetNumber(3);
}

void SimpleCalculator::on_fourPB_clicked()
{
    SetNumber(4);
}

void SimpleCalculator::on_fivePB_clicked()
{
    SetNumber(5);
}

void SimpleCalculator::on_sixPB_clicked()
{
    SetNumber(6);
}

void SimpleCalculator::on_sevenPB_clicked()
{
    SetNumber(7);
}

void SimpleCalculator::on_eightPB_clicked()
{
    SetNumber(8);
}

void SimpleCalculator::on_ninePB_clicked()
{
    SetNumber(9);
}

void SimpleCalculator::on_resetPB_clicked()
{
    curNum = nextNum = 0;
    state = true;
    SetResult("0");
}

void SimpleCalculator::on_equalPB_clicked()
{
    OpreatorStep();
    state = true;
    nextNum = 0;

}

void SimpleCalculator::on_plusPB_clicked()
{
    opt = 1;
    OpreatorStep();
}


void SimpleCalculator::on_minusPB_clicked()
{
    opt = 2;
    OpreatorStep();
}

void SimpleCalculator::on_mulPB_clicked()
{
    opt = 3;
    OpreatorStep();
}

void SimpleCalculator::on_divPB_clicked()
{
    opt = 4;
    OpreatorStep();
}
