/*
** check_redir.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/more_command/redirection
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Fri May  5 18:06:57 2017 Anselin Mackendy-pierre
** Last update Tue May  9 12:13:06 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>

#include	"basic_fonction.h"
#include	"my_basic_fonction.h"
#include	"redirection.h"
#include	"strwordtab.h"
#include	"my_execve.h"

int		exec_redir(char *name, int check)
{
  int		var;

  check--;
  if (check == 0 || check == 1)
    var = redirection_left(check, name);
  if (check == 2 || check == 3)
    var = redirection_right(check, name);
  return (var);
}

int	exec_my_redir(int *fd, char **tab, char **cp_env, int *val_retrn)
{
  char		**stock;
  char		*cmd;

  stock = the_strwordtab(tab[0], ' ');
  cmd = check_access(stock[0], stock, cp_env, val_retrn);
  if (cmd == NULL)
    return (-2);
  else
    {
      if (fd[0] != -10)
	my_dup_redir(fd);
      execve(cmd, stock, cp_env);
    }
  free(cmd);
  free_tab(stock);
  return (0);
}

void		end_redir(int *val_retrn)
{
  int		status;

  status = 0;
  wait(&status);
  if (WTERMSIG(status) == 11)
    {
      *val_retrn = 1;
      puterror("Segmentation fault (core dumped)\n");
    }
}

int		exec_cmd(char **tab, int check, char **cp_env, int *val_retrn)
{
  int		pid;
  int		fd[2];

  fd[0] = exec_redir(tab[2], check);
  fd[1] = check;
  if (fd[0] == -1)
    return (0);
  pid = fork();
  if (pid == -1)
    return (84);
  if (pid == 0)
    {
      if (exec_my_redir(fd, tab, cp_env, val_retrn) == -2)
	return (0);
    }
  else
    end_redir(val_retrn);
  return (0);
}

int		check_redir(char **tab, char **cp_env, int *val_retrn, int nbr)
{
  int		y;
  char		**stock;
  int		stop;

  y = 0;
  stop = 1;
  stock = my_sp_stock();
  if (stock == NULL)
    return (84);
  if (my_tablen(tab) <= 2)
    {
      free_tab(stock);
      return (-1);
    }
  while (stock[y] != NULL && stop != 0)
    {
      stop = my_strcmp(stock[y], tab[1]);
      y++;
    }
  free_tab(stock);
  if (nbr == 1 && stop == 0)
    return (exec_cmd(tab, y, cp_env, val_retrn));
  else if (nbr == 0 && stop == 0)
    return (0);
  return (-1);
}
