#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <assert.h> 

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
		if (!s1[i] && !s2[i])
			return (0);
	}
	return (s1[i] - s2[i]);
}

int main(void) 
{
    const char *string1 = "Hello World!";
    const char *string2 = "Hello World.";

    int result = strncmp(string1, string2, 12);
    int ft_result = ft_strncmp(string1, string2, 12);

    // printf("%i\n", result);
    // printf("%i\n", ft_result);
    assert(result == ft_result);

    const char *string3 = "!";
    const char *string4 = " ";

    int result2 = strncmp(string1, string2, 1);
    int ft_result2 = ft_strncmp(string1, string2, 1);

    // printf("%i\n", result);
    // printf("%i\n", ft_result);
    assert(result2 == ft_result2);
}