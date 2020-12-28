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
    opt = 3;
    opt = 1;
}

SimpleCalculator::~SimpleCalculator()
{
    delete ui;
}

void SimpleCalculator::SetResult(QString str)
{
    ui->resultLbl->setText(str);
}

void SimpleCalculator::ComputeEng(int n)
{
    SetResult(QString::number(n));
    if(state){
        curNum = n;
        state = false;
    }
    else{
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
        }
        nextNum = n;
        cout<<curNum<<" "<<nextNum<<endl;
    }
}

void SimpleCalculator::OpreatorStep()
{
    SetResult(QString::number(curNum));
    state = false;
}

void SimpleCalculator::on_zeroPB_clicked()
{
    ComputeEng(0);
}


void SimpleCalculator::on_onePB_clicked()
{
    ComputeEng(1);
}

void SimpleCalculator::on_twoPB_clicked()
{
    ComputeEng(2);
}

void SimpleCalculator::on_threePB_clicked()
{
    ComputeEng(3);
}

void SimpleCalculator::on_fourPB_clicked()
{
    ComputeEng(4);
}

void SimpleCalculator::on_fivePB_clicked()
{
    ComputeEng(5);
}

void SimpleCalculator::on_sixPB_clicked()
{
    ComputeEng(6);
}

void SimpleCalculator::on_sevenPB_clicked()
{
    ComputeEng(7);
}

void SimpleCalculator::on_eightPB_clicked()
{
    ComputeEng(8);
}

void SimpleCalculator::on_ninePB_clicked()
{
    ComputeEng(9);
}

void SimpleCalculator::on_resetPB_clicked()
{
    curNum = nextNum = 0;
    state = true;
    SetResult("0");
}

void SimpleCalculator::on_equalPB_clicked()
{
    ComputeEng(0);
    nextNum = 0;
    SetResult(QString::number(curNum));
    state = true;

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
    nextNum = 1;
    opt = 3;
    OpreatorStep();
}
