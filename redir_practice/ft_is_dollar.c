/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:36:54 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/17 05:23:30 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_double_quoted(char *line, int i)
{
	int	dq_open;
	int	j;

	dq_open = 0;
	j = -1;
	while (++j < i)
	{
		if (line[j] == D_QUOTE && !dq_open)
			dq_open = 1; 
		else if (line[j] == D_QUOTE && dq_open)
			dq_open = 0;
	}
	if (!dq_open)
		return (0);
	while (line[++j] && line[j] != D_QUOTE)
		;
	if (line[j] == D_QUOTE)
		return (1);
	else
		return (0);
}

int	ft_is_dollar(char *line, int i)
{
	if (line[i] == '$')
	{
		if (!ft_is_char_quoted(line, i, 0, line[i]
			|| ft_is_double_quoted(line, i))
				return (1);
	}
	return (0);
}


char	*ft_get_dollar_value(char *str, int i)
{
	char	*env_name;
	int	len;
	int	j;

	j = i;
	while (ft_is_digit(str[++j]) || ft_is_alpha(str[j]) || str[j] == '_')
		;
	if (!ft_malloc_splchar(&env_name, (j - i) + 1))
		return (NULL);
	j = i;
	while (ft_is_digit(str[++j]) || ft_is_alpha(str[j]) || str[j] == '_')
		env_name[j - i - 1] = str[j];
}

int	ft_size_dollar(char *str, int i)
{
}
