/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   get_next_line.c                                    ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/10 18:20:47 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/10/10 19:43:39 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

ssize_t	my_read(int fd, void *buf)
{
	return (read(fd, buf, BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*ret;


	return (ret);
}
