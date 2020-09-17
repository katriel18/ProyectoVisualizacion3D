#include "ProyectoVisualizacion3D.h"
#include "OpenGLWidget.h"
ProyectoVisualizacion3D::ProyectoVisualizacion3D(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    OGLW = new OpenGLWidget();
    ui.verticalLayout->addWidget(OGLW);
   
    
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

//SCALE ++
void ProyectoVisualizacion3D::on_pushButton_5_clicked()
{

    //1.0 
    if (OGLW->SCALE < 2.0) {
        OGLW->SCALE = OGLW->SCALE + 0.1f;
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

/// SCALE --
void ProyectoVisualizacion3D::on_pushButton_9_clicked() {

    if (OGLW->SCALE > 0.0) {
        OGLW->SCALE = OGLW->SCALE - 0.1f;
    }
    OGLW->update();

}

//ROTAR RotateX[-359, 359]  
void ProyectoVisualizacion3D::on_pushButton_10_clicked() {

    if (OGLW->GRADOX >-360) {
        OGLW->GRADOX = OGLW->GRADOX - 1;
    }
    OGLW->ROTATEX = true;
    OGLW->update();
   
}

void ProyectoVisualizacion3D::on_pushButton_11_clicked() {
   
    if (OGLW->GRADOX < 360) {
        OGLW->GRADOX = OGLW->GRADOX +1;
    }
    OGLW->ROTATEX = true;
    OGLW->update();
}

//ROTAR Y 
void ProyectoVisualizacion3D::on_pushButton_12_clicked() {

    if (OGLW->GRADOY > -360) {
        OGLW->GRADOY = OGLW->GRADOY - 1;
    }
    OGLW->ROTATEY = true;
    OGLW->update();

}

void ProyectoVisualizacion3D::on_pushButton_13_clicked() {

    if (OGLW->GRADOY < 360) {
        OGLW->GRADOY = OGLW->GRADOY + 1;
    }
    OGLW->ROTATEY = true;
    OGLW->update();
}
//ROTAR Z 
void ProyectoVisualizacion3D::on_pushButton_14_clicked() {

    if (OGLW->GRADOZ > -360) {
        OGLW->GRADOZ = OGLW->GRADOZ - 1;
    }
    OGLW->ROTATEZ = true;
    OGLW->update();

}

void ProyectoVisualizacion3D::on_pushButton_15_clicked() {

    if (OGLW->GRADOZ < 360) {
        OGLW->GRADOZ = OGLW->GRADOZ + 1;
    }
    OGLW->ROTATEZ = true;
    OGLW->update();
}
//SegmentsX[3, 1000]