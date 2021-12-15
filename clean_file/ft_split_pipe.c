/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:15:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/14 02:36:51 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_init_pipe_split(char ***ret, char **str, int *i, int *j)
{
	if (!ft_malloc_dblchar(ret, 1))
		return (0);
	if (!ft_malloc_splchar(str, 1))
		return (0);
	*i = -1;
	*j = 0;
	return (1);
}

char	**ft_pipe_split(char *rdline, int *k)
{
	char	**ret;
	char	*str;
	int		i;
	int		j;

	if (!ft_init_pipe_split(&ret, &str, &i, &j))
		return (NULL);
	while (rdline[++i])
	{
		if (rdline[i] == '|')
		{
			if(!ft_is_char_quoted(rdline, i, j, rdline[i]))
			{
				(*k)++;
				ret = ft_double_realloc(str, ret);
				str = NULL;
				j = i + 1;
			}
			else
				str = ft_realloc(str, rdline[i]);
		}
		else
			str = ft_realloc(str, rdline[i]);
	}
	return (ft_double_realloc(str, ret));
}
