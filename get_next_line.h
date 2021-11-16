#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strdup_modified(char *s1, int end, int *f);
char	*ft_strjoin_modified(char *s1, char *s2, int end);
char	*ft_cpy(char *src, int start, int *f);
int		ft_search(char *s);
int		ft_strlen(const char *s);
int		ft_read(int fd, char **res, char **line, int *f);
int		get_next_line(int fd, char **line);
int		ft_tmp_fate(char **tmp, char **line, int *f);
int		ft_fill_the_line(char *r, int i, int *f, char **line);

#endif
