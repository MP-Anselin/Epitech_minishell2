/*
** main.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/include
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr 11 19:09:44 2017 Anselin Mackendy-pierre
** Last update Wed Apr 12 18:05:02 2017 Anselin Mackendy-pierre
*/

#ifndef		_MY_MAIN_H_
# define	_MY_MAIN_H_

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"my_cd.h"
#include	"get_next_line.h"
#include	"env.h"
#include	"stock_tab.h"
#include	"basic_fonction.h"
#include	"strwordtab.h"
#include	"check_error.h"
#include	"pipe_other.h"
#include	"my_basic_fonction.h"
#include	"my_exit.h"
#include	"my_execve.h"
#include	"redirection.h"

int		promt(char *user);
char		**copy_env(char **env);

#endif		/* !MY_MAIN_H_ */
