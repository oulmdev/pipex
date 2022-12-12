#include "pipex.h"

int ft_strlen(char *s)
{
    int i;
    
    if (!s)
        return (0);
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}