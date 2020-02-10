
#version 330

in vec3 inPostion;


void main(){

	gl_Position = vec4(inPostion,1.0);
}