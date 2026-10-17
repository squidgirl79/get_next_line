/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   get_next_line_utils.c                              ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/17 21:36:15 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/10/17 22:48:44 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_new_buffer_size(char *ptr, char *blorbo);

int	inspect_blorbo(char *blorbo)
{
	int	index;

	index = 0;
	while (index < BUFFER_SIZE)
		if (blorbo[index++] == '\n')
			return (0);
	return (1);
}

char	*drain_blorbo(char *blorbo)
{
	int		content;
	int		index;
	char	*ret;

	if (!*blorbo)
	{
		ret = (char *)malloc(sizeof(char));
		if (!ret)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	content = 0;
	index = 0;
	while (index++ < BUFFER_SIZE)
		if (*blorbo++ == '\n')
			break ;
	while (index++ < BUFFER_SIZE)
		content++;
	ret = (char *)malloc(content + 1 * sizeof(char));
	if (!ret)
		return (NULL);
	index = 0;
	while (index < content)
		ret[index++] = *blorbo++;
	ret[index] = '\0';
	return (ret);
}

void	clean_blorbo(char *blorbo)
{
	int	i;

	i = 0;
	while (i++ < BUFFER_SIZE)
		*blorbo++ = '\0';
}

char	*feed_blorbo(char *ret, char *blorbo)
{
	char	*new_ret;
	size_t	alloc_size;
	int		index;
	int		blorbo_index;

	alloc_size = gnl_new_buffer_size(ret, blorbo);
	new_ret = (char *)malloc((alloc_size + 2) * sizeof(char));
	if (!new_ret)
		return (NULL);
	index = 0;
	blorbo_index = 0;
	while (ret[index])
	{
		new_ret[index] = ret[index];
		index++;
	}
	while (blorbo_index++ < BUFFER_SIZE)
	{
		new_ret[index++] = *blorbo;
		if (*blorbo++ == '\n')
			break ;
	}
	new_ret[index] = '\0';
	free(ret);
	return (new_ret);
}

size_t	gnl_new_buffer_size(char *ptr, char *blorbo)
{
	size_t	ret;
	int		index;

	ret = 0;
	index = 0;
	while (*ptr++)
		ret++;
	while (index < BUFFER_SIZE)
	{
		if (blorbo[index++] == '\n')
			break ;
		ret++;
	}
	return (ret);
}
