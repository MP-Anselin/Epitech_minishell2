/*
** my_pipes.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Fri May  5 17:49:07 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:49:10 2017 Anselin Mackendy-pierre
*/

#ifndef		_MY_PIPES_H_
# define	_MY_PIPES_H_

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdlib.h>

#include	"basic_fonction.h"
#include	"stock_tab.h"
#include	"strwordtab.h"
#include	"my_execve.h"
#include	"my_basic_fonction.h"
#include	"check_error.h"
#include	"pipe_other.h"
#include	"my_exit.h"

typedef struct	S_info_pipes
{
  int	*name;
  int	*in;
  int	*out;
  int	max_pipe;
}		t_info_pipes;

int		execve_pipe(char *str, char **cp_env, int *val_return);
int		check_break(char *str, char **cp_env, t_info_pipes *pip, int *i);
void		free_pipes(t_info_pipes *pip, char **str);
void		free_tab(char **tab);

#endif		/* !MY_PIPES_H */
