#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int	len;
	int	i;
	int	j;

	if (!s1 && !s2)
		return (NULL);
	j = 0;
	len = ft_strlen (s1) + ft_strlen (s2);
	strjoin = (char *)malloc ((len + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	return (strjoin);
}