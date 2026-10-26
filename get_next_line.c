/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   get_next_line.c                                    ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/10 18:20:47 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/10/26 13:12:11 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	drain_blorbo(char **ret, char *blorbo);

int		return_value_not_ready(char *ret);

char	*get_next_line(int fd)
{
	static char	blorbo[BUFFER_SIZE + 1] = {0};
	char		*ret;

	ret = NULL;
	while (return_value_not_ready(ret))
	{
		if (*blorbo)
			drain_blorbo(&ret, blorbo);
		if (!*blorbo)
			if (read(fd, blorbo, BUFFER_SIZE) < 1)
				return (ret);
	}
	return (ret);
}
