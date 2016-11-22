#include "scope.h"

void count_materials(char *file, t_env *env){
    char *line;
    char **split;
    int fd;

    if (check_file(file) == true){
        fd = open (file, O_RDONLY);
        if (fd != -1){
            while (get_next_line(fd, &line)){
                split = ft_strsplit(line,' ');
                if (split[0] != NULL && ft_strcmp(split[0], "newmtl") == 0)
                    (env->num_materials)++;
            }
        }
    }
}

void  save_materials(split[1], env){

}

