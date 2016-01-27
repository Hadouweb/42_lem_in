#include "libft.h"

char	*ft_strdup_limit(const char *s1, char c)
{
	size_t	i;
	char	*str;

	str = (char *)ft_memalloc(
		ft_strlen_limit(s1, c) * sizeof(char) + 1);
	i = 0;
	while (s1[i] && s1[i] != c)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}