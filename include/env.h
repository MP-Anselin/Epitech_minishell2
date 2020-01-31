/*
** env.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu Mar 23 19:09:06 2017 Anselin Mackendy-pierre
** Last update Tue Apr 11 23:44:59 2017 Anselin Mackendy-pierre
*/

#ifndef		ENV_H_
# define	ENV_H_

#include	"stock_tab.h"

char		**copy_env(char **env);
int		check_error_setenv(char *line, char **cp_env);
int		check_search(char **cp_env, char *line);
char		*cut_str(char *str, int var, int nbr);
int		line_check_nbr_arg(char *str);
char		**my_setenv(char **cp_env, char *line, int var);
char		**my_unsetenv(char **cp_env, char *line);

# endif		/* ENV_H_ */
