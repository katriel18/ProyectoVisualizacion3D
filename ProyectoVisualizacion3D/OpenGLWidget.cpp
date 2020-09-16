#include <glew.h>
#include <iostream>
using namespace std;
#include "OpenGLWidget.h"


OpenGLWidget::OpenGLWidget(QWidget* parent):
	QOpenGLWidget(parent)
{

}

OpenGLWidget::~OpenGLWidget()
{

}


void OpenGLWidget::initializeGL() {
	
	//glewInit();


	/*glewExperimental = GL_TRUE;
	//ERROR
	if (glewInit() != GLEW_OK) {
		cout << "ERROR AL INICIAR GLEW";
		
	}*/
	// Vertex Array Objects
	GLuint VAO;
	// Vertex Buffer Object
	GLuint VBO;

	
	int numberOfVertices;


	numberOfVertices = 1;
	GLfloat m_Vertices[3] = {
		0.0f, 0.0f, 0.0f
	};


}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}