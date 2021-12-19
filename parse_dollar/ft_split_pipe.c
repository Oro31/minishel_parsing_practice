/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:15:23 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/19 16:29:33 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*the function ft_pipe_split is used to create a table of strings
from the line extracted with readline, the separateur used is | 
the separateur will be valid if it's not between quotes
the line is freed at the end of the function
the function return a table of strings
that you will have to free before the end of your program*/

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

static int ft_realloc_previous_str(char **str, char ***ret, int i)
{
	if (*str)
		(*ret) = ft_double_realloc(*str, *ret);
	(*str) = NULL;
	return (i + 1);
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
				j = ft_realloc_previous_str(&str, &ret, i);
			}
			else
				str = ft_realloc(str, rdline[i]);
		}
		else
			str = ft_realloc(str, rdline[i]);
	}
	free(rdline);
	return (ft_double_realloc(str, ret));
}
