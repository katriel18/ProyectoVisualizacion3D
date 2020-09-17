#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProyectoVisualizacion3D.h"

#include "OpenGLWidget.h"
/*
QT_BEGIN_NAMESPACE
namespace Ui { class ProyectoVisualizacion3D; }
QT_END_NAMESPACE*/

class ProyectoVisualizacion3D : public QMainWindow
{
    Q_OBJECT

public:
    ProyectoVisualizacion3D(QWidget *parent = Q_NULLPTR);

private:
    Ui::ProyectoVisualizacion3DClass ui;

private slots:
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
   void on_pushButton_3_clicked();
   void on_pushButton_4_clicked();

   void on_pushButton_5_clicked();

private:
    OpenGLWidget *OGLW;
};
