/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:52:54 by rvalton           #+#    #+#             */
/*   Updated: 2021/12/04 08:04:44 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (argv[1][i] && argv[1][i] != '|')
		i++;
	if (!argv[1][i])
	{
		printf("no pipe\n");
		return (0);
	}
	j = 0;
	while (j < i && argv[1][j] != S_QUOTE && argv[1][j] != D_QUOTE)
		j++;
	ret = ft_is_quote_open(argv[1], i, j);
	printf("ret = %d\n", ret);
	if (ret)
	{
		if (ft_is_quote_close(argv[1], i, ret))
			printf("pipe quoted\n");
	}
	else
		printf("is pipe\n");
	return (0);
}
