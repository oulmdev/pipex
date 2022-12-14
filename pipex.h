/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:07:20 by moulmoud          #+#    #+#             */
/*   Updated: 2022/12/14 02:28:02 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

/*      Error strings       */

#define PIPE "Error: Faild to create the pipe"
#define ARGS "Error: Wrong number of argumment"
#define FDIN "pipex: input"
#define FDOU "pipex: output"

/*          struct          */


typedef struct  s_pipex
{
	pid_t	id;
	char	**cmds1;
	char	**cmds2;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	int		fdinput;
   	int		fdoutput;
	int		pip[2];
}t_pipex;

/*         Functions        */

int		fixed_len_word(char *s, int i);
int		fixed_count_word(char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_substr(char *s, unsigned int start, size_t len);

/*           END            */

#endif
