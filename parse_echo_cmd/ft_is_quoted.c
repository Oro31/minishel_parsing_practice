/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quoted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:36:54 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/12 19:52:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_new_sq(int ret, int which_q, int *lst_q)
{
	if (!ret)
	{
		*lst_q = which_q;
		return (which_q);
	}
	else if (which_q == *lst_q)
	{
		if (ret < 3)
			*lst_q = 0;
		else
			*lst_q = ret - which_q;
		return (*lst_q);
	}
	else
	{
		if (ret == 3)
			*lst_q = 0;
		else
		{
			*lst_q = which_q;
			return (3);
		}
		return (0);
	}
}

int	ft_is_quote_open(char *line, int i, int j)
{
	int	ret;
	int	lst_q;

	lst_q = 0;
	ret = 0;
	while (line[j] && j < i)
	{
		if (line[j] == S_QUOTE)
			ret = ft_new_sq(ret, 1, &lst_q);
		else if (line[j] == D_QUOTE)
			ret = ft_new_sq(ret, 2, &lst_q);
		j++;
	}
	return (ret);
}

int	ft_is_quote_close(char *line, int i, int ret_oq)
{
	int	j;
	
	j = i;
	while (line[++j])
	{
		if (ret_oq == 1 && line[j] == S_QUOTE)
			return (1);
		else if (ret_oq == 2 && line[j] == D_QUOTE)
			return (1);
		else if (ret_oq == 3 && (line[j] == S_QUOTE || line[j] == D_QUOTE))
			return (1);
	}
	return (0);
}
