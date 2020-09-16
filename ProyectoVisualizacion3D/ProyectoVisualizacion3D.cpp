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
   

    OGLW->figura = 1;
    OGLW->update();
  

}
void ProyectoVisualizacion3D::on_pushButton_2_clicked()
{
    
    OGLW->figura = 2;
    OGLW->update();


}

void ProyectoVisualizacion3D::on_pushButton_3_clicked()
{
    if (OGLW->fill == false) {
        OGLW->fill = true;


    }
    else {
        OGLW->fill = false;

    }

    OGLW->update();

}

void ProyectoVisualizacion3D::on_pushButton_4_clicked()
{

    if (OGLW->wire == false) {
        OGLW->wire = true;
        

    }else {
        OGLW->wire = false;
       
    }

    OGLW->update();
    
}