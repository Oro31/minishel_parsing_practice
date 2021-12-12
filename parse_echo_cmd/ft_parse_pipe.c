/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:15:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/12 19:52:42 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_char_quoted(char *line, int i, int j, char c)
{
	int ret;

	ret = 0;
	if (line[i] != c)
		return (0);
	while (j < i && line[j] != S_QUOTE && line[j] != D_QUOTE)
		j++;
	ret = ft_is_quote_open(line, i, j);
	if (ret)
	{
		if (ft_is_quote_close(line, i, ret))
			return (0);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

char	**ft_pipe_split(char *rdline, int *k)
{
	char	**ret;
	char	*str;
	int		i;
	int		j;

	if (!ft_malloc_dblchar(&ret, 1))
		return (NULL);
	if (!ft_malloc_splchar(&str, 1))
		return (NULL);
	i = 0;
	j = 0;
	while (rdline[i])
	{
		if (ft_is_char_quoted(rdline, i, j, '|'))
		{
			(*k)++;
			ret = ft_double_realloc(str, ret);
			str = NULL;
			j = i + 1;
		}
		else
			str = ft_realloc(str, rdline[i]);
		i++;
	}
	ret = ft_double_realloc(str, ret);
//	free(str);
	return (ret);
}
