#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <sys/types.h>
# include <sys/select.h>
# include <sys/wait.h>

# define S_QUOTE 39
# define D_QUOTE 34

enum e_redir
{
	RED_IN = 1,
	RED_OUT,
	RED_READ,
	RED_APPEND
};

typedef struct s_cmd	t_cmd;

struct	s_cmd
{
	char	**argv;
	int	*redir;
	int	size_red;
	int		is_cmd_after_pipe;
	int		pos;
	t_cmd	*nxt;
};

int	ft_prompt(t_cmd **cmd);

t_cmd	*ft_hadd_tolist_cmd(t_cmd *list, char **split, int is_pipe, int pos);
t_cmd	*ft_eadd_tolist_cmd(t_cmd *list, char **split, int is_pipe, int pos);
void	ft_free_list_cmd(t_cmd **list, int del);

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

int	ft_is_quote_needed(char *arg, int i);

int	ft_new_quote(int ret, int which_q, int *lst_q);
int	ft_is_quote_open(char *line, int i, int ret_oq);
int	ft_is_quote_close(char *line, int i, int ret_oq);
int	ft_is_char_quoted(char *line, int i, int j, char c);

char	**ft_pipe_split(char *rdline, int *k);

int	ft_is_space(char *line, int i, int j);
char	**ft_cmdline_split(char *line);

char	**ft_redir_split(char **argv);

void	ft_fill_clean_str(char **tmp, char *str);
char	*ft_clean_str(char *str);
char	**ft_clean_cmdchar(char **cmd_char);

int	ft_is_dollar(char *line, int i);
char	*ft_get_dollar_value(char *str, int i);
int	ft_size_dollar(char *str, int i);

char	**ft_dollar_parse(char **cmd_char);

#endif