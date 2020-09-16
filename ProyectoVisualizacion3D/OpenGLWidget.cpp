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
	 programID = LoadShaders("vertex_core.glsl", "fragment_core.glsl");


	//////////////////////////////////////////////////////////////////////////////////

			// Consigue una manija para nuestro uniforme "MVP"
	 MatrixID = glGetUniformLocation(programID, "MVP");

	// Matriz de proyecci�n: 45 Campo de visi�n, relaci�n 4:3, rango de visualizaci�n: 0,1 unidad <-> 100 unidades
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Matriz de c�mara
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, -3), // La c�mara est� en (4,3,-3), en el espacio mundial
		glm::vec3(0, 0, 0), // y mira el origen
		glm::vec3(0, 1, 0)  // La cabeza est� hacia arriba (establecida en 0,-1,0 para mirar al rev�s)
	);
	// Matriz de modelo: una matriz de identidad (el modelo estar� en el origen)
	glm::mat4 Model = glm::mat4(1.0f);
	// Nuestra ModelViewProjection : multiplicaci�n de nuestras 3 matrices
	MVP = Projection * View * Model; // Recuerde, la multiplicaci�n de la matriz es al rev�s

//////////////////////////////////////////////////////////////////////////////////


	// Nuestros v�rtices. Tres flotantes consecutivos hacen un v�rtice 3D; tres v�rtices consecutivos hacen un tri�ngulo.
	// Un cubo tiene 6 caras con 2 tri�ngulos cada una, esto significa 6*2=12 tri�ngulos, y 12*3 v�rtices
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f, // tri�ngulo 1 : comienza
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // tri�ngulo 1 : termina
		1.0f, 1.0f,-1.0f, // tri�ngulo 2 : comienza
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // tri�ngulo 2 : termina
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};

	
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
/*
	if (f1 == true) {
		pintarFigura(vertices_f1);
	}
	else if (f2 == true) {
		pintarFigura(vertices_f2);
	}
	*/
}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {


	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (f1 == true) {
		
	
	// Use our shader
	glUseProgram(programID);

	//////////////////////////////////////////////////////////////

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	//////////////////////////////////////////////////////////////

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

	// 12*3 los �ndices comienzan en 0 -> 12 tri�ngulos -> 6 cuadrados
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

	glDisableVertexAttribArray(0);
	
	}
}



void OpenGLWidget::pintarFigura( float vertices[])
{

	
}
