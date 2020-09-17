#include "libs.h"			//siempre debe ir primero
#include "OpenGLWidget.h"

#include "Sphere.h"
#include "Sphere2.h"

OpenGLWidget::OpenGLWidget(QWidget* parent) :
	QOpenGLWidget(parent)
{
	figura = 0;
	fill = false;
	wire = false;

	SCALE = 1.0f;

	colorID1 = 0.0f;
	colorID2 = 0.0f;
	colorID3 = 0.0f;
}
OpenGLWidget::~OpenGLWidget()
{

	// Limpieza de VBO y sombreador figuras
	glDeleteBuffers(1, vbo);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, vao);
	// Limpieza de VBO y sombreador plano
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(planoID);
	glDeleteVertexArrays(1, &VAO);
	
}


void OpenGLWidget::initializeGL() {

	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}


	/*
	// Habilitar prueba de profundidad
	glEnable(GL_DEPTH_TEST);
	// Acepta fragmento si esta mas cerca de la c�mara que el anterior.
	glDepthFunc(GL_LESS);

	// Elimina triangulos que lo normal no es hacia la c�mara
	glEnable(GL_CULL_FACE);
	*/

	// Create and compile our GLSL program from the shaders
	 programID = LoadShaders("vertex_core.glsl", "fragment_core.glsl");

	//uniforme "MVP"
	  MatrixID = glGetUniformLocation(programID, "MVP");

	  colorID1 = glGetUniformLocation(programID, "colorIn1");
	  colorID2 = glGetUniformLocation(programID, "colorIn2");
	  colorID3 = glGetUniformLocation(programID, "colorIn3");
	 
	  planoInit();
}
void OpenGLWidget::resizeGL(int w, int h) {

}
void OpenGLWidget::paintGL() {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//DIBUJAR PLANO
	planoDisplay();
	//SELECCIONAR FIGURA
	if (figura == 1) {
		seleccionarFigura(1);//triangulo
	}else if (figura == 2) {
		seleccionarFigura(2);//cuadrado
	}
	else if (figura == 3) {
		seleccionarFigura(3);//esfera 1
	}else if (figura == 4) {
		seleccionarFigura(4);//esfera 2
	}

	if (figura != 0) {

		// Use our shader
		glUseProgram(programID);

		//escalamiento
		myScalingMatrix = scale(mat4(1.0), vec3(SCALE, SCALE, SCALE));

		//Envie nuestra transformacion al sombreador "MVP"
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &myScalingMatrix[0][0]);
		//glUniformMatrix4fv(MatrixID, 1, GL_FALSE, value_ptr(myScalingMatrix));	//Incluir la libreria type_ptr
			
		// 1er bufer de atributo: vertices
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
			glDrawArrays(GL_TRIANGLES, 0, numVertices);

		}

		if(wire) {
			//DIBUJA EL MARCO DE TRIANGULOS
			glProgramUniform1f(programID, colorID1, 1.0f);
			glProgramUniform1f(programID, colorID2, 1.0f);
			glProgramUniform1f(programID, colorID3, 0.0f);
			glDrawArrays(GL_LINE_LOOP, 0, numVertices);	
		}
	glDisableVertexAttribArray(0);
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
		

		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);

		glGenBuffers(1, vbo);
		// put the vertices into buffer #0
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_f1), &vertices_f1, GL_STATIC_DRAW);

		numVertices = 3;
	}else if (figura == 2) {

		static const GLfloat vertices_f2[] = {
		-0.5f,  0.5f, 0.0f, 
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f, 

		-0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f, 
		 0.5f, -0.5f, 0.0f, 
			};
		
		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);

		glGenBuffers(1, vbo);
		// put the vertices into buffer #0
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_f2), &vertices_f2, GL_STATIC_DRAW);

		numVertices = 6;
	}
	else if (figura == 3) {
		Sphere mySphere(5,5);
		vector<int> ind = mySphere.getIndices();
		vector<vec3> vert = mySphere.getVertices();
		//vector<vec2> tex = mySphere.getTexCoords();
		//vector<vec3> norm = mySphere.getNormals();
		vector<float> pvalues;  // vertex positions
		//vector<float> tvalues;  // texture coordinates
		//vector<float> nvalues;  // normal vectors
		int numIndices = mySphere.getNumIndices();
		for (int i = 0; i < numIndices; i++) {
			pvalues.push_back((vert[ind[i]]).x);
			pvalues.push_back((vert[ind[i]]).y);
			pvalues.push_back((vert[ind[i]]).z);

			//tvalues.push_back((tex[ind[i]]).s);
			//tvalues.push_back((tex[ind[i]]).t);
			//nvalues.push_back((norm[ind[i]]).x);
			//nvalues.push_back((norm[ind[i]]).y);
			//nvalues.push_back((norm[ind[i]]).z);
		}
		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);
		glGenBuffers(1, vbo); // put the vertices into buffer #0

		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, pvalues.size() * sizeof(GLfloat), &pvalues[0], GL_STATIC_DRAW); // put the texture coordinates into buffer #1

		//glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		//glBufferData(GL_ARRAY_BUFFER, nvalues.size() * sizeof(GLfloat), &nvalues[0], GL_STATIC_DRAW);

		numVertices = mySphere.getNumIndices();


		/*Sphere mySphere(5, 5);

		numVertices = mySphere.getNumVertices();
		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);

		glGenBuffers(1, vbo);
		// put the vertices into buffer #0
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER,mySphere.getVertices().size(), &mySphere.getVertices(), GL_STATIC_DRAW);

		*/


	}
	else if (figura == 4) {

		Sphere2 mySphere2(5);//Sphere mySphere(48);

		std::vector<int> ind = mySphere2.getIndices();
		std::vector<glm::vec3> vert = mySphere2.getVertices();
		//std::vector<glm::vec2> tex = mySphere2.getTexCoords();
		//std::vector<glm::vec3> norm = mySphere2.getNormals();
		std::vector<float> pvalues; // vertex positions
		//std::vector<float> tvalues; // texture coordinates
		//std::vector<float> nvalues; // normal vectors

		
		for (int i = 0; i < mySphere2.getNumIndices(); i++) {
			pvalues.push_back((vert[ind[i]]).x);
			pvalues.push_back((vert[ind[i]]).y);
			pvalues.push_back((vert[ind[i]]).z);
			//tvalues.push_back((tex[ind[i]]).s);
			//tvalues.push_back((tex[ind[i]]).t);
			//nvalues.push_back((norm[ind[i]]).x);
			//nvalues.push_back((norm[ind[i]]).y);
			//nvalues.push_back((norm[ind[i]]).z);
		}


		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);
		glGenBuffers(1, vbo);//glGenBuffers(3, vbo);
		// put the vertices into buffer #0
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, pvalues.size() * 4, &pvalues[0], GL_STATIC_DRAW);

/*
		// put the texture coordinates into buffer #1
		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glBufferData(GL_ARRAY_BUFFER, tvalues.size() * 4, &tvalues[0], GL_STATIC_DRAW);
		// put the normals into buffer #2
		glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
		glBufferData(GL_ARRAY_BUFFER, nvalues.size() * 4, &nvalues[0], GL_STATIC_DRAW);
*/
		numVertices = mySphere2.getNumIndices();
	}
	
}

//PLANO
void OpenGLWidget::planoInit()
{

	// Crear y compilar el programa GLSL desde los shaders
	 planoID = LoadShaders("vertex_plano.glsl", "fragment_plano.glsl");
	 //uniforme "MVP"
	 matrixPlanoID = glGetUniformLocation(planoID, "MVP");
	 colorPlanoID1 = glGetUniformLocation(planoID, "colorIn1");
	 colorPlanoID2 = glGetUniformLocation(planoID, "colorIn2");
	 colorPlanoID3 = glGetUniformLocation(planoID, "colorIn3");

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// PLANO
	static const GLfloat g_vertex_buffer_data[] = {
	   0.0f, 0.0f, 0.0f,
	   0.8f, 0.0f, 0.0f,

	   0.0f, 0.0f, 0.0f,
	   0.0f, 0.8f, 0.0f,

	   0.0f, 0.0f, 0.0f,
	   0.0f,  0.0f, 8.0f,
	};
	
	// Generar un buffer, poner el resultado en el vertexbuffer que acabamos de crear
	glGenBuffers(1, & VBO);
	// Los siguientes comandos le darAn caracter�sticas especiales al 'vertexbuffer'
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Darle nuestros vErtices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void OpenGLWidget::planoDisplay()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	// Use our shader
	glUseProgram(planoID);
	
	//Escalamiento
	myScalingMatrixPlano = scale(mat4(1.0), vec3(SCALE, SCALE, SCALE));

	//Envie nuestra transformacion al sombreador "MVP"
	glUniformMatrix4fv(matrixPlanoID, 1, GL_FALSE, &myScalingMatrixPlano[0][0]);
	
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(
		0,                  
		3,                  
		GL_FLOAT,           
		GL_FALSE,           
		0,                    
		(void*)0           
	);

	//verde rojo azul
	glProgramUniform1f(planoID, colorPlanoID1, 0.0f);
	glProgramUniform1f(planoID, colorPlanoID2, 1.0f);
	glProgramUniform1f(planoID, colorPlanoID3, 0.0f);
	glDrawArrays(GL_LINES, 0, 2); 
	glProgramUniform1f(planoID, colorPlanoID1, 1.0f);
	glProgramUniform1f(planoID, colorPlanoID2, 0.0f);
	glProgramUniform1f(planoID, colorPlanoID3, 0.0f);
	glDrawArrays(GL_LINES, 2, 2);
	glProgramUniform1f(planoID, colorPlanoID1, 0.0f);
	glProgramUniform1f(planoID, colorPlanoID2, 0.0f);
	glProgramUniform1f(planoID, colorPlanoID3, 1.0f);
	glDrawArrays(GL_LINES, 4, 2);
	glDisableVertexAttribArray(0);

}
