#version 440

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;

out vec4 fs_color;

uniform float colorIn1;
uniform float colorIn2;
uniform float colorIn3;
void main()
{

	//fs_color = vec4(0.0f,0.0f,1.0f, 1.0f);

	fs_color = vec4(colorIn1,colorIn2,colorIn3, 1.0f);
}
