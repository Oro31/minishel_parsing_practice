#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <sys/types.h>
# include <sys/wait.h>

# define S_QUOTE 'S'
# define D_QUOTE 'D'

int	g_status;

typedef struct s_cmd	t_cmd;

struct	s_cmd
{
	char	**argv;
	int		is_cmd_after_pipe;
	int		pos;
	t_cmd	*nxt;
};

int	ft_prompt(char **str);

t_cmd	*ft_hadd_tolist_cmd(t_cmd *list, char **split, int is_pipe, int pos);
t_cmd	*ft_eadd_tolist_cmd(t_cmd *list, char **split, int is_pipe, int pos);
void	ft_free_list_cmd(t_cmd *list);

int	ft_malloc_dblchar(char ***tmp, int size);
int	ft_malloc_splchar(char **tmp, int size);

char	**ft_double_realloc(char *str, char **split);
char	*ft_realloc(char *str, char c);

int		ft_size_list_cmd(t_cmd *list);
void	ft_print_list_cmd(t_cmd *list);

void	ft_print_str(char *str);
int	ft_strlen(char *str);
char	*ft_str_copy(char *str);
int	ft_strncomp(char *str, char *comp, int n);

int	ft_new_sq(int ret, int which_q, int *lst_q);
int	ft_is_quote_open(char *line, int i, int j);
int	ft_is_quote_close(char *line, int i, int ret_oq);

/*char	**ft_double_realloc(char *str, char **split);*/

#endif
