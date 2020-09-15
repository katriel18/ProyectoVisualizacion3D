#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent):
	QOpenGLWidget(parent)
{

}

OpenGLWidget::~OpenGLWidget()
{

}


void OpenGLWidget::initializeGL() {

}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}