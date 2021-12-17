/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:04:56 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/16 13:13:28 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_double_realloc(char *str, char **split)
{
	char	**tmp;
	int		i;

	i = -1;
	while (split[++i]);
	if (!ft_malloc_dblchar(&tmp, i + 2))
		return (NULL);
	tmp[i] = ft_str_copy(str);
	while (--i >= 0)
		tmp[i] = ft_str_copy(split[i]);
	free(split);
	return (tmp);
}

char	*ft_realloc(char *str, char c)
{
	char	*tmp;
	int		i;

	i = ft_strlen(str);
	if (!ft_malloc_splchar(&tmp, i + 2))
		return (NULL);
	tmp[i] = c;
	while (--i >= 0)
		tmp[i] = str[i];
	free(str);
	return (tmp);
}
