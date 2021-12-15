/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmdline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:15:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/14 04:09:06 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_init_cmdline_split(char ***ret, char **str, int *i, int *j)
{
	if (!ft_malloc_dblchar(ret, 1))
		return (0);
	if (!ft_malloc_splchar(str, 1))
		return (0);
	*i = -1;
	*j = 0;
	return (1);
}

char	**ft_cmdline_split(char *line)
{
	char	**ret;
	char	*str;
	int		i;
	int		j;

	if (!ft_init_cmdline_split(&ret, &str, &i, &j))
		return (NULL);
	while (line[++i])
	{
		if (line[i] == ' ')
		{
			if (!ft_is_char_quoted(line, i, j, line[i]) && i > 0)
			{
				ret = ft_double_realloc(str, ret);
				str = NULL;
				j = i + 1;
			}
			else
				str = ft_realloc(str, line[i]);
		}
		else
			str = ft_realloc(str, line[i]);
	}
	return (ft_double_realloc(str, ret));
}
