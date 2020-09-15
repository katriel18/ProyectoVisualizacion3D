#include "ProyectoVisualizacion3D.h"

#include "OpenGLWidget.h"

ProyectoVisualizacion3D::ProyectoVisualizacion3D(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


    OpenGLWidget *OGLW = new OpenGLWidget();
    ui.verticalLayout->addWidget(OGLW);

}

//widget
//openGLWidget

//verticalLayout