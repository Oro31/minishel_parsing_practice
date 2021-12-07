/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:57:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/05 13:02:08 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_size_list_cmd(t_cmd *list)
{
	t_cmd	*tmp;
	int		i;

	if (list == NULL)
		return (0);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nxt;
		i++;
	}
	return (i);
}

void	ft_print_list_cmd(t_cmd *list)
{
	t_cmd	*tmp;
	int		i;

	if (list != NULL)
	{
		tmp = list;
		while (tmp)
		{
			i = -1;
			while (tmp->argv[++i])
			{
				ft_print_str(tmp->argv[i]);
				ft_print_str(" ");
			}
			ft_print_str("\n");
			tmp = tmp->nxt;
		}
	}
}
