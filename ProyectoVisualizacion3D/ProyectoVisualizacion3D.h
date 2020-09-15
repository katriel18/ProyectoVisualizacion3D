#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProyectoVisualizacion3D.h"

class ProyectoVisualizacion3D : public QMainWindow
{
    Q_OBJECT

public:
    ProyectoVisualizacion3D(QWidget *parent = Q_NULLPTR);

private:
    Ui::ProyectoVisualizacion3DClass ui;
};
