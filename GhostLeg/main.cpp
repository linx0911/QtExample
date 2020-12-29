#include "ghostleggenerator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GhostLegGenerator w;
    w.show();
    return a.exec();
}
