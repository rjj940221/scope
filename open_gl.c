//
// Created by Robert JONES on 2016/11/25.
//

#include "scope.h"

void init_ogl(t_env *env)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    env->ogl.window = glfwCreateWindow(800, 600, "Scop", NULL, NULL);
    if (env->ogl.window == NULL)
    {
        ft_putstr("Failed to create GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(env->ogl.window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        ft_putstr("Failed to initialize GLEW\n");
        exit(EXIT_FAILURE);
    }
    glfwSetKeyCallback(env->ogl.window, key_callback);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void bind_buffers(t_env *env)
{
    printf ("num faces %d \n", env->num_faces);
    for (int i = 0; i < env->num_faces; i++)
    {
        printf("%d  ", env->ogl.indices[i]);
    }
    puts("");
    printf ("num vertecy %d \n", env->num_vertex);
    for (int i = 0; i < env->num_vertex; i++)
    {
        printf("%f  ", env->ogl.vertices[i]);
    }
    puts("");

    glGenVertexArrays(1, &env->ogl.VAO);
    glGenBuffers(1, &env->ogl.VBO);
    glGenBuffers(1, &env->ogl.EBO);
    glBindVertexArray(env->ogl.VAO);
        glBindBuffer(GL_ARRAY_BUFFER, env->ogl.VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * env->num_vertex, env->ogl.vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ogl.EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLint) * env->num_faces, env->ogl.indices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_TRUE, 4 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    env->ogl.shader_program = load_program("vertex.glsl", "fragment.glsl");
    env->ogl.matrix_pass = glGetUniformLocation(env->ogl.shader_program, "MVP");
}

void loop_ogl(t_env *env)
{
    while(!glfwWindowShouldClose(env->ogl.window))
    {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUniformMatrix4fv(env->ogl.matrix_pass, 1, GL_FALSE, &env->mvp[0][0]);
        glUseProgram(env->ogl.shader_program);
        glBindVertexArray(env->ogl.VAO);
        glDrawElements(GL_TRIANGLES, env->num_faces, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(env->ogl.window);
    }
    glfwTerminate();
}

