// 42 HEADER

#ifndef MINISHELL_H
# define MINISHELL_H

// TODO: rm stdio inc when project is complete
#include <stdio.h>

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define ABS(x) x > 0 ? x : -x 

// operators list : ; && || | > >> <

enum	e_node_type
{
	COMMAND,
	AND,
	OR,
	PIPE,
	REDIR_OUT_1,
	REDIR_OUT_2,
	REDIR_IN_1
};


typedef struct	s_node
{
	enum e_node_type type;
	char **args;
	struct s_node *left;
	struct s_node *right;
}				t_node;

typedef int		(*t_eval_node_function)(t_node *n, void *options);

char **environment;

// PROCESS MANAGEMENT
int	process_container(t_node *root);
int	eval_node(t_node *node, void *options);
int	run_process(t_node *n, void *options);

// BTREE UTILS
void	btree_delete(t_node *node);
t_node  *btree_node_new(int type, char **args);

// ENV UTILS
int     valid_envar_id(const char *n);
char    *get_key_value(char **tab, char *key);
int     keycmp(char *str, char *key);
int     push_envar(const char *str);


// BUILTINS
int		ft_export(char *args[]);
int		echo(char *args[]);
int		env(char *args[]);
int     change_dir(char *arg[]);
int     ft_unset(char *arg[]);

// ERROR MANAGEMENT
void    ft_perrorc(const char *from, const char *arg, const char *msg);

#endif
