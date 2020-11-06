#include "libft.h"

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;

	if (n == 0)
		return (0);

	while (s1[i] == s2[i] && s1[i] && s2[i] && i <= n)
	{
		i++;
		// if (!s1[i] && !s2[i])
		// 	return (0);
	}
	if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
	// return (s1[i] - s2[i]);
}
