#include "scope.h"

int main(int ac, char **av) {
    t_env env;

    if (ac != 2) {
        ft_putstr("please specify one and only one file.\n");
        return (0);
    }
    init_env(&env);
    init_ogl(&env);
    read_obj(av[1], &env);
    bind_buffers(&env);
    loop_ogl(&env);
    ft_exit("ran successfully\n", EXIT_SUCCESS, &env);
    return 1;
}