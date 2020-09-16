#include "libs.h"			//siempre debe ir primero
#include "OpenGLWidget.h"

#include "Sphere.h"
OpenGLWidget::OpenGLWidget(QWidget* parent) :
	QOpenGLWidget(parent)
{
	figura = 0;
	fill = false;
	wire = false;

	colorID1 = 0.0;
	colorID2 = 0.0;
	colorID3 = 0.0;
}
OpenGLWidget::~OpenGLWidget()
{

	// Limpieza de VBO y sombreador
	glDeleteBuffers(1, vbo);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, vao);
}


void OpenGLWidget::initializeGL() {

	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}
/*
	// Habilitar prueba de profundidad
	glEnable(GL_DEPTH_TEST);
	// Acepta fragmento si est� m�s cerca de la c�mara que el anterior.
	glDepthFunc(GL_LESS);

	// Elimina tri�ngulos que lo normal no es hacia la c�mara
	glEnable(GL_CULL_FACE);
*/
	// Create and compile our GLSL program from the shaders
	 programID = LoadShaders("vertex_core.glsl", "fragment_core.glsl");
	// Obtenga un identificador para nuestro uniforme "MVP"
	  MatrixID = glGetUniformLocation(programID, "MVP");

	
	  colorID1 = glGetUniformLocation(programID, "colorIn1");
	  colorID2 = glGetUniformLocation(programID, "colorIn2");
	  colorID3 = glGetUniformLocation(programID, "colorIn3");
	 
	  


		

}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {


	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (figura == 1) {
		seleccionarFigura(1);
	}
	else if (figura == 2) {
		seleccionarFigura(2);
	}

	if (figura != 0) {



		// Use our shader
		glUseProgram(programID);


		// 1er b�fer de atributo: vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);






	if (fill) {

		glProgramUniform1f(programID, colorID1, 0.52f);
		glProgramUniform1f(programID, colorID2, 0.52f);
		glProgramUniform1f(programID, colorID3, 0.52f);
		glPointSize(4.0f);
		// DIBUJA LOS TRIANGULOS PINTADOS !
		glDrawArrays(GL_TRIANGLES, 0, numVertices);



	}


	if (wire) {
		//DIBUJA EL MARCO DE TRIANGULOS
		glProgramUniform1f(programID, colorID1, 1.0f);
		glProgramUniform1f(programID, colorID2, 1.0f);
		glProgramUniform1f(programID, colorID3, 0.0f);
		glDrawArrays(GL_LINE_LOOP, 0, numVertices);

		glDisableVertexAttribArray(0);
	}


}
}



void OpenGLWidget::seleccionarFigura(int figura)
{



	if (figura == 1) {

		static const GLfloat vertices_f1[] = {
				-0.5f, -0.5f, 0.0f,
				0.5f, -0.5f, 0.0f,
				 0.0f,  0.5f, 0.0f
			};
		numVertices = 3;

		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);

		glGenBuffers(1, vbo);
		// put the vertices into buffer #0
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_f1), &vertices_f1, GL_STATIC_DRAW);


	}else if (figura == 2) {

		static const GLfloat vertices_f2[] = {
		-0.5f,  0.5f, 1.0f, 
		 0.5f,  0.5f, 1.0f,
		 0.5f, -0.5f, 1.0f, 

		-0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f, 
		 0.5f, -0.5f, 0.0f, 
			};
		numVertices = 6;
		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);

		glGenBuffers(1, vbo);
		// put the vertices into buffer #0
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_f2), &vertices_f2, GL_STATIC_DRAW);

	}
		


	
}



//colores//255
//(128,128,128) plomo  0.52
//1 1 0 amarillo