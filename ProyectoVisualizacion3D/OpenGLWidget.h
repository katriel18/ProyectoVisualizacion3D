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

    mat4 model;

    float SCALE;
    
    const float toRadians = 3.14159265f / 180.0f;
    int GRADOX;
    int GRADOY;
    int GRADOZ;


    int numVertices;
    int figura;
    boolean fill;
    boolean wire;
    void seleccionarFigura(int figura);

    //PLANOXYZ
    GLuint planoID;
    GLuint VAO;
    GLuint VBO;
    GLuint matrixPlanoID;
    mat4 modelPlano;

    GLfloat colorPlanoID1;
    GLfloat colorPlanoID2;
    GLfloat colorPlanoID3;
    void planoInit();
    void planoDisplay();

};
