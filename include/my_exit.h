/*
** my_exit.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/include
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr 11 19:00:58 2017 Anselin Mackendy-pierre
** Last update Wed Apr 26 15:12:49 2017 Anselin Mackendy-pierre
*/

#ifndef		_MY_EXIT_H_
# define	_MY_EXIT_H_

#include	"stock_tab.h"
#include	"my_pipes.h"

void		free_tab(char **tab);
int		exit_error(char *str);
void		my_exit(int nbr, t_stock_tab *tab, char *user, int val_return);

#endif		/* _MY_EXIT_H_ */
