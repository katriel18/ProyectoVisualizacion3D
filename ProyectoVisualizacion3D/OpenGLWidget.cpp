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



	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	programID = LoadShaders("src/SimpleVertexShader.vertexshader", "src/SimpleFragmentShader.fragmentshader");
	float vertices_f1[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	float vertices_f2[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
	};


	/*if (f1 == true) {
		pintarFigura(vertices_f1);
	}
	else if (f2 == true) {
		pintarFigura(vertices_f2);
	}*/
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_f1), vertices_f1, GL_STATIC_DRAW);


}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {


	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Use our shader
	glUseProgram(programID);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	

}



void OpenGLWidget::pintarFigura( float vertices[])
{
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	
}
