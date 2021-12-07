/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:05:31 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/03 00:57:18 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_hadd_tolist_cmd(t_cmd *list, char **split, int is_pipe, int pos)
{
	t_cmd	*newelem;

	newelem = malloc(sizeof(t_cmd));
	if (!newelem)
	{
		ft_print_str("malloc failed\n");
		return (NULL);
	}
	newelem->argv = split;
	newelem->is_cmd_after_pipe = is_pipe;
	newelem->pos = pos;
	newelem->nxt = list;
	return (newelem);
}

t_cmd	*ft_eadd_tolist_cmd(t_cmd *list, char **split, int is_pipe, int pos)
{
	t_cmd	*newelem;
	t_cmd	*tmp;

	newelem = malloc(sizeof(t_cmd));
	if (!newelem)
	{
		ft_print_str("malloc failed\n");
		return (NULL);
	}
	newelem->argv = split;
	newelem->is_cmd_after_pipe = is_pipe;
	newelem->pos = pos;
	newelem->nxt = NULL;
	if (list == NULL)
		return (newelem);
	else
	{
		tmp = list;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = newelem;
		return (list);
	}
}

void	ft_free_list_cmd(t_cmd *list)
{
	t_cmd	*tmp;
	int		i;

	while (list)
	{
		i = -1;
		if (list->argv)
			while (list->argv[++i])
				free(list->argv[i]);
		free(list->argv);
		tmp = list->nxt;
		free(list);
		list = tmp;
	}
}
