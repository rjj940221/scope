#version 330 core

in vertexColor;
in vec3 ourColor;

out vec4 color;

void main()
{
    color = (ourColor, 1.0f);
}
