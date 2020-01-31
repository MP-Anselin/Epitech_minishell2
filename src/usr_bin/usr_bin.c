/*
** usr_bin.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/usr_bin
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Fri Mar 24 10:38:48 2017 Anselin Mackendy-pierre
** Last update Mon May  8 16:27:06 2017 Anselin Mackendy-pierre
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<unistd.h>

#include	"strwordtab.h"
#include	"basic_fonction.h"
#include	"my_basic_fonction.h"
#include	"my_execve.h"

int	usr_bin(char *command, char **tab, char **cp_env, int *val_return)
{
  pid_t	pid;

  pid = fork();
  if (pid == 0)
    {
      if (execve(command, tab, cp_env) == -1)
	return (84);
    }
  else if (pid  == -1)
    return (84);
  wait(&pid);
  if (WTERMSIG(pid) == 11)
    {
      puterror("Segmentation fault (core dumped)\n");
      *val_return = 1;
    }
  return (0);
}
