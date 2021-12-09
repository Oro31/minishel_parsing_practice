/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rdline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:15:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/05 12:00:59 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_space(char *line, int i, int j)
{
	int ret;

	ret = 0;
	if (line[i] != ' ')
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

char	**ft_cmdline_split(char *line)
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
	while (line[i])
	{
		if (ft_is_space(line, i, j))
		{
			ret = ft_double_realloc(str, ret);
			str = NULL;
			j = i + 1;
		}
		else
			str = ft_realloc(str, line[i]);
		i++;
	}
	ret = ft_double_realloc(str, ret);
//	free(str);
	return (ret);
}
