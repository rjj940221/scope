#include "libft.h"

static double	get_fraction(const char *nptr)
{
    double	res;
    double	div;

    res = 0.0;
    div = 10.0;
    if (*nptr == '.' || *nptr == ',')
    {
        ++nptr;
        while (ft_isdigit(*nptr))
        {
            res += (*(nptr++) - '0') / div;
            div *= 10.0;
        }
    }
    return (res);
}

static double	get_double(const char *nptr)
{
    double	res;

    res = 0.0;
    while (ft_isdigit(*nptr))
    {
        res *= 10.0;
        res += *(nptr++) - '0';
    }
    res += get_fraction(nptr);
    return (res);
}

double			ft_atod(const char *nptr)
{
    double	res;
    int		neg;

    neg = 1;
    if (nptr[0] == '-')
        ++nptr;
    else
        neg = 0;
    if (nptr[0] == '+')
        ++nptr;
    res = get_double(nptr);
    if (neg)
        res = -res;
    return (res);
}
