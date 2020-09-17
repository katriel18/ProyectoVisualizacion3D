#include "ProyectoVisualizacion3D.h"
#include "OpenGLWidget.h"
ProyectoVisualizacion3D::ProyectoVisualizacion3D(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    OGLW = new OpenGLWidget();
    ui.verticalLayout->addWidget(OGLW);
   
    ui.horizontalSlider->setMinimum(2);
    ui.horizontalSlider->setMaximum(50);
    ui.label_2->setText("0");
    
}
//TRIANGULO
void ProyectoVisualizacion3D::on_pushButton_clicked()
{
   

    OGLW->figura = 1;
    OGLW->update();
  

}
//CUADARADO
void ProyectoVisualizacion3D::on_pushButton_2_clicked()
{
    
    OGLW->figura = 2;
    OGLW->update();


}

//FILL
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

//WIRE
void ProyectoVisualizacion3D::on_pushButton_4_clicked()
{

    if (OGLW->wire == false) {
        OGLW->wire = true;
        

    }else {
        OGLW->wire = false;
       
    }

    OGLW->update();
    
}

//SCALA
void ProyectoVisualizacion3D::on_pushButton_5_clicked()
{

    if (OGLW->SCALE == 1.0f || OGLW->SCALE == 0.5f) {
        OGLW->SCALE=2.0f;


    }else if(OGLW->SCALE == 2.0f) {
        OGLW->SCALE = 0.5f;
    }
    OGLW->update();

}
//ESFERA 1
void ProyectoVisualizacion3D ::on_pushButton_6_clicked() {

    OGLW->figura = 3;
    OGLW->update();

}

//ESFERA 2
void ProyectoVisualizacion3D::on_pushButton_7_clicked() {

    OGLW->figura = 4;
    OGLW->update();

}
//TORUS
void ProyectoVisualizacion3D::on_pushButton_8_clicked() {

    OGLW->figura = 5;
    OGLW->update();

}