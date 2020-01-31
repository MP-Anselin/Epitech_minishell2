/*
** more_command.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/include
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Wed Apr 12 17:32:03 2017 Anselin Mackendy-pierre
** Last update Wed Apr 12 17:35:03 2017 Anselin Mackendy-pierre
*/

#ifndef		_MORE_COMMAND_H_
# define	_MORE_COMMAND_H_

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdlib.h>

#include	"basic_fonction.h"
#include	"check_error.h"
#include	"stock_tab.h"
#include	"strwordtab.h"
#include	"my_execve.h"
#include	"pipe_other.h"
#include	"my_basic_fonction.h"
#include	"strwordtab.h"
#include	"my_malloc.h"
#include	"redirection.h"

int		check_env_cd(char *line, char **wordtab, char **cp_env);

#endif		/* !_MORE_COMMAND_H_ */
