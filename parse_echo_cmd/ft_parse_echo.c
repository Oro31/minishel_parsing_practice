/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:42:50 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/09 14:28:26 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_unclosed_quote(char *str, int j)
{
	int	k;

	if (line[j] != S_QUOTE && line[j] != D_QUOTE)
		return (0);
	k = j + 1;
	while (line[k] && line[k] != line[j])
		k++;
	if (line[k] != line[j])
		return (1);
	return (0);
}

void	ft_fill_arg_echo(char **ret, char *arg, int i)
{
	int	j;
	int	k;

	k = 0;
	j = i;
	while (arg[j])
	{
		if ((arg[j] != S_QUOTE && arg[j] != Q_QUOTE) || ft_is_unclosed_quote(arg, j))
		{
			(*ret)[k] = arg[j];
			k++;
		}
		i++;
	}
}

int	ft_malloc_frstarg_echo(char **ret, char *arg)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (*arg && arg && arg[i] = ' ')
		i++;
	j = i;
	while (arg[j])
	{
		if ((arg[j] != S_QUOTE && arg[j] != Q_QUOTE) || ft_is_unclosed_quote(arg, j))
			k++;
		j++;
	}
	if (!ft_malloc_splchar(ret, k))
		return (0);
	ft_fill_arg_echo(char **ret, char *arg, int i);
	return (1);
}

int ft_parse_echo(t_cmd *cmd)
{
	char	*ret;
	int	i;
	int	j;
	int	k;

	i = 0;
	while (cmd->argv[++i])
	{
		j = 0;
		while (cmd->argv[i][j] == ' ')
			j++;

		   (	|| ft_is_unclose_quote(cmd->argv[i], j))
		if (cmd->argv[i][j] == S_QUOTE || cmd->argv[i][j] == Q_QUOTE)
	}
}
