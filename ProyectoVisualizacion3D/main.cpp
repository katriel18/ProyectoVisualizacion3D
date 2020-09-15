#include "ProyectoVisualizacion3D.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProyectoVisualizacion3D w;
    w.show();
    return a.exec();
}
