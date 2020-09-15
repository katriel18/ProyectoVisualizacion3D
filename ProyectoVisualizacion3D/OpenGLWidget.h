#pragma once

#include <QtWidgets/qopenglwidget.h>

class OpenGLWidget : public QOpenGLWidget 
{
 public:
     OpenGLWidget(QWidget* parent = Q_NULLPTR);
    ~OpenGLWidget();
   
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};
