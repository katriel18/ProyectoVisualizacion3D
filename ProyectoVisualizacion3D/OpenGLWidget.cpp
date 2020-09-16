#include "libs.h"			//siempre debe ir primero
#include "OpenGLWidget.h"


OpenGLWidget::OpenGLWidget(QWidget* parent):
	QOpenGLWidget(parent)
{
	f1 = false;
	f2 = false;
}

OpenGLWidget::~OpenGLWidget()
{


}


void OpenGLWidget::initializeGL() {
	
	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}



}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {
	
	if(f1==true){
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	
	}else if (f2== true){
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
	}
	

}



void OpenGLWidget::pintar()
{
	
	
}
