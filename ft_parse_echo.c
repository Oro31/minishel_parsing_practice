/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:42:50 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/13 05:47:49 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fill_arg_echo(char **ret, char *arg, int i)
{
	int	j;
	int	k;

	k = 0;
	j = i;
	while (arg[j])
	{
		if (arg[j] != S_QUOTE && arg[j] != D_QUOTE)
		{
			(*ret)[k] = arg[j];
			k++;
		}
		else if (ft_is_char_quoted(arg, j, 0, arg[j]))
		{
			(*ret)[k] = arg[j];
			k++;
		}
		j++;
	}
}

static char	*ft_parse_arg_echo(char *arg, int pos)
{
	char	*tmp;
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	if (pos == 1)
		while (*arg && arg && arg[i] == ' ')
			i++;
	j = i;
	while (arg[j])
	{
		if (arg[j] != S_QUOTE && arg[j] != D_QUOTE)
			k++;
		else if (ft_is_char_quoted(arg, j, 0, arg[j]))
			k++;
		j++;
	}
	if (!ft_malloc_splchar(&tmp, k + 1))
		return (NULL);
	ft_fill_arg_echo(&tmp, arg, i);
	return (tmp);
}

static char	*ft_join_arg_echo(char *str1, char *str2, int i)
{
	char	*tmp;
	int	size;
	int	k;
	int	j;

	size = ft_strlen(str1) + ft_strlen(str2);
	if (!ft_malloc_splchar(&tmp, size + 1))
		return (NULL);
	k = -1;
	while (str1[++k])
		tmp[k] = str1[k];
	if (i > 1)
		tmp[k] = ' ';
	else
		k = -1;
	j = -1;
	while (str2[++j])
		tmp[++k] = str2[j];
	free(str1);
	free(str2);
	return (tmp);
}

char *ft_parse_echo(t_cmd *cmd)
{
	char	*ret;
	char	*arg;
	int	i;

	if (!ft_malloc_splchar(&ret, 1))
		return (NULL);
	i = 0;
	while (cmd->argv[++i])
	{
		arg = ft_parse_arg_echo(cmd->argv[i], i);
		ret = ft_join_arg_echo(ret, arg, i);
	}
	return (ret);
}
