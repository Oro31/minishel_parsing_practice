#include "minishell.h"

static void	ft_handler(int signum)
{
	if (signum == SIGQUIT)
	{
		if (g_status == 1)
			g_status = 2;
		else
			g_status = 1;
	}
	else if (SIGINT)
	{
		ft_print_str("\n$>");
		if (g_status == 1)
			g_status = 2;
		else
			g_status = 1;
	}
}

int	main(void)
{
	struct sigaction	action;
	t_estr	*ppt;
	int		ret;

	action.sa_handler = ft_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	ppt = NULL;
	ret = 0;
	g_status = 0;
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	while (!ret || g_status)
	{
		ret = ft_prompt(&ppt);
	}
	printf("\n");
	printf("size list = %d\n", ft_size_listr(ppt));
	ft_print_list(ppt);
	ft_free_listr(ppt);
	return (0);
}
