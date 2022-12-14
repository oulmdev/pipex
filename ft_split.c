/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmoud <moulmoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:00:52 by moulmoud          #+#    #+#             */
/*   Updated: 2022/12/14 02:06:10 by moulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"




static int	count_word(char *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			return (fixed_count_word(s,c));
		}
		i++;
	}
	i = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}


static int	len_word(char *s, char c, int i)
{
	int	size;

	size = 0;
	if (s[i] == '\'' || s[i] == '"')
	{
		return (fixed_len_word(s, i));
	}
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

char		**ft_split(char *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = count_word(s, c);
	if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = len_word(s, c, i);
		if (!(strs[j] = ft_substr(s, i, size)))
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += size;
	}
	strs[j] = 0;
	return (strs);
}

// int main()
// {
// 	char *st = "awk {count++} END {print count}";
// 	char **str = ft_split(st,' ');

// 	while (*str)
// 	{
// 		printf("|%s|\n",*str);
// 		str++;
// 	}
// }
