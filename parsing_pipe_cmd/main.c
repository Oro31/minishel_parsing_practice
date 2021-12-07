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
	t_cmd				*cmd;
	int					ret;

	action.sa_handler = ft_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	cmd = NULL;
	ret = 0;
	g_status = 0;
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	while (!ret || g_status)
		ret = ft_prompt(&cmd);
	printf("\n");
	ft_print_list_cmd(cmd);
	printf("nb cmd : %d\n", ft_size_list_cmd(cmd));
	return (0);
}
