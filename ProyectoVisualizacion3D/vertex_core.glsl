#version 440

// Datos de vértices de entrada, diferentes para todas las ejecuciones de este sombreador.
layout(location = 0) in vec3 vertexPosition_modelspace;

// Valores que permanecen constantes para toda la malla.
uniform mat4 MVP;

void main(){

    // Posición de salida del vértice, en el espacio del clip : MVP * posición
	gl_Position =vec4(vertexPosition_modelspace,1.0f);

}

