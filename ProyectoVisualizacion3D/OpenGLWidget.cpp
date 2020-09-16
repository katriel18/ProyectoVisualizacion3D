#include "libs.h"			//siempre debe ir primero
#include "OpenGLWidget.h"


OpenGLWidget::OpenGLWidget(QWidget* parent):
	QOpenGLWidget(parent)
{

}

OpenGLWidget::~OpenGLWidget()
{

}


void OpenGLWidget::initializeGL() {
	
	glewInit();
	/*glewExperimental = GL_TRUE;
	//ERROR
	if (glewInit() != GLEW_OK) {
		cout << "ERROR AL INICIAR GLEW";
		
	}*/

	
	GLuint VAO;
	
	GLuint VBO;

	
	int dimVertices = 3;
	int numberOfVertices = 1;
	GLfloat m_Vertices[3] = {
		0.0f, 0.0f, 0.0f
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(
		GL_ARRAY_BUFFER,
		dimVertices * sizeof(GLfloat),
		m_Vertices,
		GL_STATIC_DRAW
	);


}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(50.0f);
	// Draw the primitive GL_POINTS
	glDrawArrays(GL_POINTS, 0, 3);

}