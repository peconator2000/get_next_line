#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*start;
	char	*mid1;
	char	*mid2;

	mid1 = s1;
	mid2 = s2;
	while (*mid1)
		mid1++;
	while (*mid2)
		mid2++;
	res = malloc(sizeof(*res) * (mid1 - s1 + mid2 - s2 + 1));
	mid1 = s1;
	if (!res)
		return (NULL);
	start = res;
	while (*mid1)
		*res++ = *mid1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (start);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	char	*start;
	char	*mid;

	if (!s1)
		return (NULL);
	mid = s1;
	while (*mid)
		mid++;
	res = malloc(sizeof(char) * (mid - s1 + 1));
	start = res;
	if (!res)
		return (NULL);
	while (*s1)
		*res++ = *s1++;
	*res = '\0';
	return (start);
}

char	*ft_strndup(char *s1)
{
	char	*res;
	char	*start;
	char	*mid;

	if (!s1)
		return (NULL);
	mid = s1;
	while (*mid && *mid != '\n')
		mid++;
	res = malloc(sizeof(char) * (mid - s1 + 1));
	start = res;
	if (!res)
		return (NULL);
	while (*s1 && *s1 != '\n')
		*res++ = *s1++;
	*res = '\0';
	return (start);
}

int	is_nl(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, int len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;
	ssize_t				i;

	dst2 = dst;
	src2 = src;
	i = 0;
	if (dst > src)
	{
		i = (long int)len;
		while (--i >= 0)
			dst2[i] = src2[i];
	}
	else if (dst < src)
	{
		i = -1;
		while (++i < (long int)len)
			dst2[i] = src2[i];
	}
	return (dst);
}
