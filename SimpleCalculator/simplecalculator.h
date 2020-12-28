#ifndef SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleCalculator; }
QT_END_NAMESPACE

class SimpleCalculator : public QMainWindow
{
    Q_OBJECT

public:
    SimpleCalculator(QWidget *parent = nullptr);
    ~SimpleCalculator();

    void SetResult(QString str);
    void OpreatorStep();
    void ComputeEng(int n);

private slots:
    void on_zeroPB_clicked();

    void on_onePB_clicked();

    void on_twoPB_clicked();

    void on_threePB_clicked();

    void on_fourPB_clicked();

    void on_fivePB_clicked();

    void on_sixPB_clicked();

    void on_sevenPB_clicked();

    void on_eightPB_clicked();

    void on_ninePB_clicked();

    void on_resetPB_clicked();

    void on_equalPB_clicked();

    void on_plusPB_clicked();

    void on_minusPB_clicked();

    void on_mulPB_clicked();

private:
    Ui::SimpleCalculator *ui;
    int curNum;
    int nextNum;
    int opt;
    bool state;
};
#endif // SIMPLECALCULATOR_H
