/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:36:54 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/15 05:25:19 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_quote(char c)
{
	return (c == S_QUOTE || c == D_QUOTE);
}

static char	ft_new_open_q(char *arg, char open_q, int k)
{
	if (!open_q)
		return (arg[k]);
	else if (open_q  == arg[k])
		return (0);
	else
		return (open_q);
}

static int	ft_is_open_q_close(char *arg, int i, char quote)
{
	int	j;

	j = i;
//	if (!(*quote))
//		(*quote) = arg[i];
	while (arg[++j] && (arg[j] != quote))
		;
	return (arg[i] != quote);
}

static int	ft_is_frst_quote(char *arg, int i);
{
	int	j;

	j = i;
	while (j > 0 && !ft_is_quote(arg[j]))
		j--;
	if (j = i)

}

int	ft_is_quote_needed(char *arg, int i)
{
	int	k;
	char	open_q;

	open_q = 0;
	k = -1;
	while (++k < i)
	{
		if (ft_is_quote(arg[k]))
		{

			printf("k %d\n", k);
			open_q = ft_new_open_q(arg, open_q, k);
		}
	}
	if (arg[i] == open_q)
		return (0);
	else
		return (ft_is_open_q_close(arg, i, open_q));
}
