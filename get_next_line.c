#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int	rd = 0;
	char c;
	if ((rd = read(fd, &c, 1) == 0))
		return (NULL);
	char *line = malloc(100000);
	char *word = line;
	*line++ = c;
	printf("%s", line);
	while ((rd = read(fd, &c, 1)) > 0 &&  c != '\n')
		*line++ = c;
	if (c == '\n')
		*line++ = '\n';
	*line = '\0';
	return (word);
}

char *gnl2(int fd)
{
	char c;
	int	rd = 0;
	if ((rd = read(fd, &c, 1)) == 0)
		return (NULL);
	char *line;
	line = malloc(100000);
	char *word;
	word = line;
	*line++ = c;
	while((rd = read(fd, &c, 1)) > 0 && c != '\n')
		*line++ = c;
	if (c == '\n')
		*line++ = '\n';
	*line = '\0';
	return (word);
}

int	main(void)
{
	int	fd = open("1.txt", O_RDWR);
	char *ret = gnl2(fd);
	printf("%s", ret);
	ret = gnl2(fd);
	printf("%s", ret);
}