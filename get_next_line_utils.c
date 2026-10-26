/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   get_next_line_utils.c                              ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/17 21:36:15 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/10/26 13:13:28 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_blorbo(char *old_ret, char *blorbo);

size_t	count_bufs(char *ptr, char *blorbo);

void	drain_blorbo(char **ret, char *blorbo)
{
	if (!*ret)
	{
		*ret = (char *)malloc(sizeof(char));
		if (!*ret)
			return ;
		**ret = 0;
	}
	*ret = append_blorbo(*ret, blorbo);
}

void	shove_blorbo(char *blorbo)
{
	int	index_src;
	int	index_dst;

	index_src = 0;
	index_dst = 0;
	while (index_src < BUFFER_SIZE)
		if (blorbo[index_src++] == DELIMITER)
			break ;
	while (index_src < BUFFER_SIZE)
		blorbo[index_dst++] = blorbo[index_src++];
	while (index_dst < BUFFER_SIZE)
		blorbo[index_dst++] = '\0';
}

char	*append_blorbo(char *old_ret, char *blorbo)
{
	char	*new_ret;
	int		i;
	char	*blorbo_start;

	blorbo_start = blorbo;
	new_ret = (char *)malloc((count_bufs(old_ret, blorbo) + 1) * sizeof(char));
	if (!new_ret)
		return (NULL);
	i = -1;
	while (old_ret[++i])
		new_ret[i] = old_ret[i];
	while (*blorbo)
	{
		if (*blorbo == DELIMITER)
		{
			new_ret[i++] = *blorbo++;
			break ;
		}
		new_ret[i++] = *blorbo++;
	}
	new_ret[i] = '\0';
	free(old_ret);
	shove_blorbo(blorbo_start);
	return (new_ret);
}

size_t	count_bufs(char *ptr, char *blorbo)
{
	size_t	size;

	size = 0;
	while (*ptr++)
		size++;
	while (*blorbo)
	{
		size++;
		if (*blorbo++ == DELIMITER)
			break ;
	}
	return (size);
}

int	return_value_not_ready(char *ret)
{
	if (!ret)
		return (1);
	while (*ret)
		if (*ret++ == DELIMITER)
			return (0);
	return (1);
}
