/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:36:54 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/17 05:03:16 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fill_dollar(char **tmp, char *str)
{
	char	*dol;
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (ft_is_dollar(str, i))
		{
			dol = ft_get_dollar_value(str, i);
			k = 0;
			while (++k < ft_size_dollar(str, i))
				(*tmp)[++j] = dol[k];
			while (ft_is_digit(str[++i]) || ft_is_alpha(str[i]
				|| str[i] == '_')
				;
		}
		(*tmp)[++j] = str[i];
	}
}

static int	*ft_interpret_dollar(char *str)
{
	char	*tmp;
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (ft_is_dollar(str, i))
			j = j + ft_size_dollar(str, i);
		else
			j++;
	}
	if (!ft_malloc_splchar(&tmp, j + 1))
		return (NULL):
	ft_fill_dollar(&tmp, str);
	return (tmp);
}

char	**ft_dollar_parse(char **cmd_char)
{
	char	**tmp;
	int	i;

	i = 0;
	while (cmd_char[i])
		i++;
	if (!ft_malloc_dblchar(&tmp, i + 1))
		return (NULL);
	i = -1;
	while (cmd_char[++i])
		tmp[i] = ft_interpret_dollar(cmd_char[i]);
	return (tmp);
}
