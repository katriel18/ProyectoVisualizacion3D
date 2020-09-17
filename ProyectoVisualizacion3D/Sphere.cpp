// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW

#include <glew.h>

#include <string>
#include <fstream>
#include <cmath>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Sphere.h"

using namespace std;
using namespace glm;

Sphere::Sphere(int segX, int segY) {
	init(segX, segY);
	for(int i=0; i<numVertices; i++){
		cout << vertices[i].x << vertices[i].y << vertices[i].z << endl;
	}
}


	void Sphere::init(int segX, int segY){
		numVertices = (segX + 1) * (segY + 1);
		numIndices = segX * segY * 6;
		for (int i = 0; i < numVertices; i++) { vertices.push_back(glm::vec3()); } // std::vector::push_back()
		for (int i = 0; i < numVertices; i++) { texCoords.push_back(glm::vec2()); } // inserts new element at
		for (int i = 0; i < numVertices; i++) { normals.push_back(glm::vec3()); } // the end of a vector and
		for (int i = 0; i < numIndices; i++) { indices.push_back(0); } // increases the vector size by 1calculate triangle vertices
		for (int i = 0; i <= segY; i++) {
			for (int j = 0; j <= segX; j++) {
				float y = (float)cos(toRadians(180.0f - i * 180.0f / segY));
				float x = -(float)cos(toRadians(j*360.0f / segX)) * (float)abs(cos(asin(y)));
				float z = (float)sin(toRadians(j*360.0f / segX)) * (float)abs(cos(asin(y)));
				vertices[i*(segX + 1)+j] = vec3(x, y, z);
				//texCoords[i*(segY + 1) + j] = vec2(((float)j / segY), ((float)i / segX));
				normals[i*(segX + 1)+j] = vec3(x,y,z);
				}
		}

		// calculate triangle indices
		for (int i = 0; i<segY; i++) {
			for (int j = 0; j<segX; j++) {
				indices[6*(i*segX + j) + 0] = i*(segX + 1) + j;
				indices[6*(i*segX + j) + 1] = i*(segX + 1) + j + 1;
				indices[6*(i*segX+ j) + 2] = (i + 1)*(segX + 1) + j;
				indices[6*(i*segX + j) + 3] = i*(segX + 1) + j + 1;
				indices[6*(i*segX + j) + 4] = (i + 1)*(segX + 1) + j + 1;
				indices[6*(i*segX + j) + 5] = (i + 1)*(segX + 1) + j;
			}
		}
	};
	float Sphere::toRadians(float degrees) { return (degrees * 2.0f * 3.14159f) / 360.0f; };

	// accessors
	int Sphere::getNumVertices() { return numVertices; }
	int Sphere::getNumIndices() { return numIndices; }
	vector<int> Sphere::getIndices() { return indices; }
	vector<vec3> Sphere::getVertices() { return vertices; }
	vector<vec2> Sphere::getTexCoords() { return texCoords; }
	vector<vec3> Sphere::getNormals() { return normals; }


