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

    GLuint vao[1];
    GLuint vbo[3];

    GLuint MatrixID;
   
    GLfloat colorID1;
    GLfloat colorID2;
    GLfloat colorID3;

    mat4 MVP;

    int numVertices;

    int figura;
    boolean fill;
    boolean wire;

    void seleccionarFigura(int figura);
};
