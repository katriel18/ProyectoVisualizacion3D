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
    //FIGURAS
    GLuint programID;

    GLuint vao[1];
    GLuint vbo[3];

    GLuint MatrixID;
   
    GLfloat colorID1;
    GLfloat colorID2;
    GLfloat colorID3;

    mat4 myScalingMatrix;

    mat4 MVP;

    int numVertices;

    int figura;

    boolean fill;
    boolean wire;

    float SCALE;

    void seleccionarFigura(int figura);

    //PLANOXYZ
    GLuint planoID;
    GLuint VAO;
    GLuint VBO;
    GLuint matrixPlanoID;
    mat4 myScalingMatrixPlano;

    GLfloat colorPlanoID1;
    GLfloat colorPlanoID2;
    GLfloat colorPlanoID3;
    void planoInit();
    void planoDisplay();

};
