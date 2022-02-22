#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char*s2);
char	*ft_strdup(char *s1);
int		is_nl(char *str);
int		ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strndup(char *s1);
void	*ft_memmove(void *dst, const void *src, int len);

#endif
