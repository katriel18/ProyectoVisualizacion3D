#pragma once
#include "libs.h"
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

public:
    GLuint programID;
    GLuint VertexArrayID;
    GLuint vertexbuffer;
    GLuint MatrixID;
    mat4 MVP;

    bool f1, f2;
    void pintarFigura(float vertices[]);
};
