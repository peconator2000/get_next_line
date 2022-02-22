#include "get_next_line.h"
#include <string.h>

static int	clean_all(char **rem, int y)
{
	if (*rem && y != 1)
	{
		free(*rem);
		*rem = NULL;
	}
	return (y);
}

static int	change_rem(char **rem, char *buf)
{
	char	*mid;

	mid = 0;
	if (*rem)
		mid = ft_strjoin(*rem, buf);
	else
		mid = ft_strdup(buf);
	if (!mid)
		return (0);
	if (*rem)
		free(*rem);
	*rem = mid;
	return (1);
}

static void	cut_rem(char *rem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!rem)
		return ;
	while (rem[i] != '\n')
		i++;
	i++;
	while (rem[i + j])
	{
		rem[j] = rem[i + j];
		j++;
	}
	rem[j] = '\0';
}

int	get_next_line(int fd, char **line)
{
	int				f;
	char			buf[BUFFER_SIZE + 1];
	static char		*rem;

	if (fd < 0)
		return (-1);
	f = 1;
	while (!is_nl(rem) && f)
	{
		f = read(fd, buf, BUFFER_SIZE);
		if (f < 0 || BUFFER_SIZE < 1)
			return (clean_all(&rem, -1));
		buf[f] = '\0';
		if (!change_rem(&rem, buf))
			return (clean_all(&rem, -1));
	}
	*line = ft_strndup(rem);
	if (!f)
		return (clean_all(&rem, 0));
	cut_rem(rem);
	if (!*line)
		return (clean_all(&rem, -1));
	return (clean_all(&rem, 1));
}
