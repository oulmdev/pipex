/*         includes         */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/*      Error strings       */

#define PIPE "Error: Faild to create the pipe"
#define ARGS "Error: Wrong number of argumment"
#define FDIN "Faild to open input file"
#define FDOU "Faild to open output file"
/*          struct          */
typedef struct  s_pipex
{
    char    **cmds1;
    char    **cmds2;
    char    *cmd1;
    char    *cmd2;
    char    *path;
    int     fdinput;
    int     fdoutput;
    int     pip[2];
}t_pipex;

/*         Functions        */

char	**ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *s);
char	*ft_strstr(char *str, char *to_find);
char    *ft_substr(char *s, unsigned int start, size_t len);
void    ft_puterror(char *s);

/*           END            */
