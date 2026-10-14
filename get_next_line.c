/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   get_next_line.c                                    ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/10 18:20:47 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/10/14 16:24:04 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_strchr(char *s, char c);

static void	gnl_strcat(char *dest, char *src);

static char	*gnl_realloc(char *ptr, size_t size);

ssize_t	my_read(int fd, void *buf)
{
	return (read(fd, buf, BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	static char	blorbo[BUFFER_SIZE] = {0};
	char		buf[BUFFER_SIZE];
	char		*ret;
	size_t		llen;
	int			i;

	i = 0;
	if (!my_read(fd, buf))
		return (NULL);
	llen = BUFFER_SIZE + 1;
	ret = (char *)malloc(llen);
	while (buf[i])
	{
		ret[i] = buf[i];
		i++;
	}
	ret[i] = '\0';
	while (!gnl_strchr(buf, '\n'))
	{
		while (buf[i] && buf[i] != '\n')
			i++;
		llen += i;
		ret = gnl_realloc(ret, llen);
		gnl_strcat(ret, buf);
		my_read(fd, buf);
	}
	ret = buf;
	return (ret);
}

// drain blorbo reads from blorbo and allocates it as the start of the resulting line
char	*drain_blorbo(char *ret, char *blorbo)
{
	size_t	content;
	int		index;

	if (!blorbo)
		return ((char *)malloc(sizeof(char)));
	content = 0;
	index = 0;
	while (index < BUFFER_SIZE)
	{
		if (index[blorbo]++ == '\n')
			break ;
		content++;
	}
	ret = (char *)malloc(content + 1 * sizeof(char));
	if (!ret)
		return (NULL);
	index = 0;
	while (index < content)
		index[ret] = index[blorbo];
	index = 0;
	while (index++ < BUFFER_SIZE)
		*blorbo++ = '\0';
	return (ret);
}

// feed blorbo writes the remainder of the buffer into blorbo
void	feed_blorbo(char *buf, char *blorbo)
{
	int		index;

	index = 0;
	while (index < BUFFER_SIZE)
		if (index[buf]++ == '\n')
			break ;
	while (index < BUFFER_SIZE)
		*blorbo++ = index[buf]++;
}

static void	gnl_strcat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
}

static int	gnl_strchr(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

static char	*gnl_realloc(char *ptr, size_t size)
{
	char	*ret;
	char	*tmp;

	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	ret = (char *)malloc(size);
	if (!ret)
		return (NULL);
	tmp = ret;
	while (size-- && *ptr)
		*tmp++ = *ptr++;
	*tmp = '\0';
	// free(ptr);
	return (ret);
}
