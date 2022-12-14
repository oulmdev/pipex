/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:59:49 by moulmoud          #+#    #+#             */
/*   Updated: 2022/12/14 02:06:14 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fixed_count_word(char *s, char c)
{
	int size;
	int i;
	int flag;

	flag = 0;
	i = 0;
	size = 0;
	while (s && s[i])
	{
		if (s[i] != '\0' && flag == 0 && (s[i] == '\'' || s[i] == '"'))
		{
			i++;
			if (s[i] == '\'' || s[i] == '"')
				i++;
			size++;
			flag++;
			while (s[i] && (s[i] != '\'' && s[i] != '"'))
				i++;
			if (s[i] == '\'' || s[i] == '"')
				i++;
			if (s[i] == '\'' || s[i] == '"')
				i++;

		}
		if (s[i] != '\0' && s[i] != c  && s[i] != '\'' && s[i] != '"')
		{
			size++;
			while (s[i] && s[i] != c && s[i] != '\'' && s[i] != '"')
				i++;
		}
		else if(s[i] != '\0')
			i++;
	}
	return (size);
}

int fixed_len_word(char *s, int i)
{
	int		len;
	char	c;

	len = 0;
	c = s[i];

	i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}
