/*
** pipe_other.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/include
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Wed Apr  5 14:52:38 2017 Anselin Mackendy-pierre
** Last update Tue Apr 18 12:43:42 2017 Anselin Mackendy-pierre
*/

#ifndef		_PIPE_OTHER_H_
# define	_PIPE_OTHER_H_
#include	"stock_tab.h"

int	more_command(t_stock_tab *tab, int *val_return);
int	my_pipes(char **str, int nbr_pipe, char **cp_env, int *val_return);

#endif		/* _PIPE_OTHER_H_ */
