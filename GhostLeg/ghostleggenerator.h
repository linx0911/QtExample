#ifndef GHOSTLEGGENERATOR_H
#define GHOSTLEGGENERATOR_H

#include <QMainWindow>
#include <QList>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class GhostLegGenerator; }
QT_END_NAMESPACE

class GhostLegGenerator : public QMainWindow
{
    Q_OBJECT

public:
    GhostLegGenerator(QWidget *parent = nullptr);
    ~GhostLegGenerator();

    void GenButton();
    QPushButton* CreateButton(int n);
    QPushButton* CreateStartButton(int n);
    QPushButton* CreateEndButton(int n);
    void reset();


private slots:
    void on_runPB_clicked();

private:
    Ui::GhostLegGenerator *ui;
    QList<QPushButton*> qStartBtnList;
    QList<QPushButton*> qEndBtnList;
    int stX, stY;
    int endX, endY;
    int yDiff;
    int btnIndex, btnW, btnH;
};
#endif // GHOSTLEGGENERATOR_H
