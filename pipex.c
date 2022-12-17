/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:00:23 by moulmoud          #+#    #+#             */
/*   Updated: 2022/12/14 18:16:52 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

char    *ft_getcmd(t_pipex pipex,char **cmds)
{
	char **paths;
	char *tmp;
	char *cmd;

	paths = ft_split(pipex.path, ':');
	if (access(cmds[0],F_OK) == 0)
		return (cmds[0]);
	while (*paths != NULL)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp,cmds[0]);
		if (!tmp || !cmd)
			return (NULL);
		free(tmp);
		if (access(cmd,F_OK) == 0)
			return (cmd);
		free(cmd);
		paths++;
	}
	return(NULL);
}

t_pipex ft_getcmds(t_pipex pipex, char **av, char **env)
{
	while (*env != NULL)
	{
		if(ft_strstr(*env,"PATH=") != NULL)
		{
			pipex.path = *env;
			break;
		}
		env++;
	}
	pipex.cmds1 = ft_split(av[2], ' ');
	pipex.cmds2 = ft_split(av[3], ' ');
	pipex.cmd1 = ft_getcmd(pipex,pipex.cmds1);
	printf("%s",pipex.cmd1);
	if (!(pipex.cmd1))
		perror("permission denied");
	pipex.cmd2 = ft_getcmd(pipex,pipex.cmds2);
	if (!(pipex.cmd2))
		perror("permission denied");

	return (pipex);
}

void ft_child(t_pipex *pipex, char **env)
{
	if (pipex->fdinput < 0)
	{
		perror("pipex");
		exit(0);
	}
	dup2(pipex->pip[1],1);
	close(pipex->pip[0]);
	dup2(pipex->fdinput,0);
	execve(pipex->cmd1,pipex->cmds1,env);
}

void ft_parrent(t_pipex *pipex, char **env)
{
	dup2(pipex->pip[0],0);
	close(pipex->pip[1]);
	dup2(pipex->fdoutput,1);
	execve(pipex->cmd2,pipex->cmds2,env);
}
void	ft_pipex(t_pipex pipex, char **env)
{
	pipex.id = fork();
	if (pipex.id == -1)
		perror("Error: ");
	if (pipex.id == 0)
	{
		ft_child(&pipex, env);
	}
	else
	{
		ft_parrent(&pipex,env);
	}
}

int ft_checkit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if ((s[i] == '\'' && s[i + 1] && s[i +1] != '"' ) || s[i] == '"')
			return(1);
		i++;
	}
	return (0);
}

int main(int ac,char *av[], char *env[])
{
	t_pipex pipex;

	if (ac != 5)
	{
		perror(ARGS);
		exit(EXIT_FAILURE);
	}
	pipex.fdinput = open(av[1], O_RDONLY);
	if (pipex.fdinput == -1)
	{
		perror(FDIN);
		exit(0);
	}
	pipex.fdoutput = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.fdoutput == -1)
	{
		perror(FDOU);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipex.pip) < 0)
		return(perror(PIPE),0);
	pipex = ft_getcmds(pipex,av,env);
	// if(!(pipex.cmd1))
	// 	perror("pipex");
	// if(!(pipex.cmd2))
	// 	perror("pipex");
	// ft_pipex(pipex,env);
	exit(EXIT_SUCCESS);
}
