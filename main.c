/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   main.c                                             ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/13 13:32:33 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/10/13 16:24:39 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	const int	fd = open("test.txt", O_RDONLY);
	char		*line;
	int			i;

	line = (char *)1;
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		printf("\n<%s>\n", line);
	}
	close(fd);
	return (0);
}
