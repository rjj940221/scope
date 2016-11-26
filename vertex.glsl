#version 330
// Input vertex data, different for all executions of this shader.
layout(location = 0)
in vec3 vertexPosition;
out vec4 myColor;
// Values that stay constant for the whole mesh.
uniform mat4 MVP;

void main(){
  // Output position of the vertex, in clip space : MVP * position

  gl_Position =  MVP * vec4(vertexPosition, 1);
//  gl_Position =  vec4(vertexPosition,1);
  myColor = vec4(gl_Position.x, gl_Position.x, gl_Position.x, 1);
  //gl_Position = vec4(vertexPosition, 1);
}

