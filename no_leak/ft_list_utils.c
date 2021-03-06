/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:57:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/19 15:53:48 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*return the number of element of a list of type t_cmd*/

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

/*print in stdout what's contain a list of type t_cmd*/

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
				if (tmp->argv[i + 1])
					ft_print_str("//");
			}
			printf(" is_pipe=%d\n", tmp->is_cmd_after_pipe);
			tmp = tmp->nxt;
		}
	}
}
