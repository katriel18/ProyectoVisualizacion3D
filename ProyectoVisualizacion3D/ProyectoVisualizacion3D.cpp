#include "ProyectoVisualizacion3D.h"

ProyectoVisualizacion3D::ProyectoVisualizacion3D(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

   
}
/*
void ProyectoVisualizacion3D::on_pushButton_clicked()
{
    cout << "boton1 presionado!" <<endl;
    if (OGLW->f2)
        OGLW->f2 = false;
    OGLW->f1 = true;
    OGLW->update();
}

void ProyectoVisualizacion3D::on_pushButton_2_clicked()
{
    cout << "boton2 presionado!" <<endl;
    if (OGLW->f1)
        OGLW->f1 = false;
    OGLW->f2 = true;
    OGLW->update();
}

void ProyectoVisualizacion3D::on_pushButton_3_clicked()
{
    cout << "boton3 presionado!" <<endl;
    OGLW->f1 = false;
    OGLW->f2 = false;
    OGLW->update();
}
*/