//
// Created by Robert JONES on 2016/11/24.
//
#include "scope.h"

char *shaderLoadSource(char *file) {
    char *re;
    char *tmp;
    char buff[BUFF_SIZE + 1];
    int fd;
    int readre;

    if (check_file(file) == false)
        return (NULL);
    if ((fd = open(file, O_RDONLY)) != -1) {
        while ((readre = read(fd, buff, BUFF_SIZE - 1)) > 0) {
            tmp = re;
            buff[readre] = '\0';
            if (re)
                re = ft_strjoin(re, buff);
            else
                re = ft_strdup(buff);
            ft_strdel(&tmp);
        }
        return (re);
    }
    return (NULL);
}

static GLuint shaderCompileFromFile(GLenum type, char *filePath) {
    char *source;
    GLuint shader;
    GLint length;
    GLint result;
    char *log;


    source = shaderLoadSource(filePath);
    if (!source)
        return 0;
    shader = glCreateShader(type);
    length = ft_strlen(source);
    glShaderSource(shader, 1, (const char **) &source, &length);
    glCompileShader(shader);
    ft_strdel(&source);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        log = malloc(length);
        glGetShaderInfoLog(shader, length, &result, log);
        fprintf(stderr, "shaderCompileFromFile(): Unable to compile %s: %s\n", filePath, log);
        ft_strdel(&log);
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

GLuint shaderAttachFromFile(GLuint program, GLenum type, char *filePath) {
    GLuint shader;

    shader = shaderCompileFromFile(type, filePath);
    if (shader != 0) {
        glAttachShader(program, shader);
    }
    return shader;
}

GLuint load_program(char *vertex_shader, char *fragment_shader) {
    GLint result;
    GLuint program_id;
    GLuint shaders[2];
    GLint length;
    char *log;

    program_id = glCreateProgram();
    shaders[0] = shaderAttachFromFile(program_id, GL_VERTEX_SHADER, vertex_shader);
    shaders[1] = shaderAttachFromFile(program_id, GL_FRAGMENT_SHADER, fragment_shader);
    glLinkProgram(program_id);
    glGetProgramiv(program_id, GL_LINK_STATUS, &result);
    if (result == GL_FALSE) {
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &length);
        log = malloc(length);
        glGetProgramInfoLog(program_id, length, &result, log);
        fprintf(stderr, "sceneInit(): Program linking failed: %s\n", log);
        ft_strdel(&log);
        glDeleteProgram(program_id);
        program_id = 0;
    }
    glDetachShader(program_id, shaders[0]);
    glDetachShader(program_id, shaders[1]);
    glDeleteShader(shaders[0]);
    glDeleteShader(shaders[1]);
    return (program_id);
}