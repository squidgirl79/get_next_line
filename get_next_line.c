/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   get_next_line.c                                    ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/10 18:20:47 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/10/17 22:52:21 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*drain_blorbo(char *blorbo);

int		inspect_blorbo(char *blorbo);

void	clean_blorbo(char *blorbo);

char	*feed_blorbo(char *ptr, char *blorbo);

char	*return_null(char *ret, char *blorbo);

char	*get_next_line(int fd)
{
	static char	*blorbo;
	char		*ret;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (!blorbo)
		blorbo = (char *)malloc(BUFFER_SIZE);
	ret = drain_blorbo(blorbo);
	clean_blorbo(blorbo);
	if (read(fd, blorbo, BUFFER_SIZE) < 1)
	{
		if (*ret)
			return (ret);
		return (return_null(ret, blorbo));
	}
	ret = feed_blorbo(ret, blorbo);
	while (inspect_blorbo(blorbo))
	{
		clean_blorbo(blorbo);
		read(fd, blorbo, BUFFER_SIZE);
		ret = feed_blorbo(ret, blorbo);
	}
	return (ret);
}

char	*return_null(char *ret, char *blorbo)
{
	free(ret);
	free(blorbo);
	return (NULL);
}
