#include "ProyectoVisualizacion3D.h"
#include "OpenGLWidget.h"
ProyectoVisualizacion3D::ProyectoVisualizacion3D(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    OGLW = new OpenGLWidget();
    ui.verticalLayout->addWidget(OGLW);
   
    
}

void ProyectoVisualizacion3D::on_pushButton_clicked()
{
    ui.pushButton_2->setText("pushButton_2");
    ui.pushButton->setText("SELECCIONADO");

    if (OGLW->f2==true)
        OGLW->f2 = false;
    OGLW->f1 = true;
    OGLW->update();
  

}
void ProyectoVisualizacion3D::on_pushButton_2_clicked()
{
    ui.pushButton->setText("pushButton_1");
    ui.pushButton_2->setText("SELECCIONADO");

    if (OGLW->f1 == true)
        OGLW->f1 = false;
    OGLW->f2 = true;
    OGLW->update();


}