

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "pipex.h"

// char *ft_fix_cmds(char **cmds)
// {
// 	int col = 0;
// 	int ln = 0;

// 	int i = 0;
// 	int j = 0;
// 	int len = 0;
// 	int indexes[4];
// 	while (cmds[ln] != NULL)
// 	{
// 		col = 0;
// 		while (cmds[ln][col] != '\0')
// 		{
// 			if (cmds[ln][col] == '\'' || cmds[ln][col] == '"')
// 			{
// 				if(i < 4)
// 				{
// 					indexes[i++] = ln;
// 					indexes[i++] = col;
// 				}
// 			}
// 			col++;
// 			len++;
// 		}
// 		ln++;
// 	}

// 	j = indexes[0];
// 	i = indexes[1] + 1;
// 	ln = indexes[2];
// 	col = indexes[3];
// 	char *cmd = malloc(len - 2 * sizeof(char));
// 	len = 0;
// 	while (j <= ln)
// 	{

// 		while (cmds[j][i] != '\0')
// 		{
// 			if(j == ln && i == col)
// 				break;
// 			cmd[len] = cmds[j][i];
// 			len++;
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 	}
// 	cmd[len] = '\0';
// 	return(cmd);
// }




// static int	fixed_count_word(char *s, char c)
// {
// 	int size;
// 	int i;
// 	int flag;

// 	flag = 0;
// 	i = 0;
// 	size = 0;
// 	while (s && s[i])
// 	{
// 		if (s[i] != '\0' && flag == 0 && (s[i] == '\'' || s[i] == '"'))
// 		{
// 			i++;
// 			if (s[i] == '\'' || s[i] == '"')
// 				i++;
// 			size++;
// 			flag++;
// 			while (s[i] && (s[i] != '\'' && s[i] != '"'))
// 				i++;
// 			if (s[i] == '\'' || s[i] == '"')
// 				i++;
// 			if (s[i] == '\'' || s[i] == '"')
// 				i++;

// 		}
// 		if (s[i] != '\0' && s[i] != c  && s[i] != '\'' && s[i] != '"')
// 		{
// 			size++;
// 			while (s[i] && s[i] != c && s[i] != '\'' && s[i] != '"')
// 				i++;
// 		}
// 		else if(s[i] != '\0')
// 			i++;
// 	}
// 	return (size);
// }

// int main()
// {
// 	char *c = "awk \"'{count++} END {print count}'\" hello";
// 	int j = fixed_count_word(c,' ');
// 	printf("%d\n",j);
// }


int main(int ac,char **arv,char **env)
{

	int pip[2];
	int fd1 = open("input",O_RDONLY);
	int fd2 = open("output",O_CREAT | O_RDWR | O_TRUNC, 0644);
	char *av[] = {"grep","Hello",NULL};
	char *av2[] = {"awk","\"{count++} END {print count}\"",NULL};
	pipe(pip);
	int i = fork();
	if(i == 0)
	{
		dup2(pip[1],1);
		close(pip[0]);
		dup2(fd1,0);
		execve("/usr/bin/grep",av,env);
	}
	else
	{
		dup2(pip[0],0);
		close(pip[1]);
		dup2(fd2,1);
		execve("/usr/bin/awk",av2,env);
	}
}

