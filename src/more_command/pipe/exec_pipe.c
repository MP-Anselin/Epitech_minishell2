/*
** exec_pipe.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/more_command/pipe
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu May  4 11:43:33 2017 Anselin Mackendy-pierre
** Last update Tue May  9 12:09:15 2017 Anselin Mackendy-pierre
*/

#include	"my_pipes.h"

int		check_break(char *str, char **cp_env, t_info_pipes *pip, int *i)
{
  char		**stock;
  int		out;
  int		in;

  in = pip->in[*i];
  out = pip->out[*i];
  close(pip->in[*i]);
  close(pip->out[*i]);
  stock = the_strwordtab(str, ' ');
  if (*i == pip->max_pipe)
    {
      if (check_env_cd(str, stock, cp_env) == -1)
	{
	  pip->in[*i] = in;
	  pip->out[*i] = out;
	  free_tab(stock);
	  return (-1);
	}
    }
  free_tab(stock);
  return (0);
}

int		execve_pipe(char *str, char **cp_env, int *val_return)
{
  char		**the_pipe;
  char		*cmd;

  the_pipe = the_strwordtab(str, ' ');
  cmd = check_access(the_pipe[0], the_pipe, cp_env, val_return);
  if (cmd != NULL)
    {
      if (execve(cmd, the_pipe, cp_env) == -1)
	{
	  free_tab(the_pipe);
	  return (84);
	}
    }
  free(cmd);
  free_tab(the_pipe);
  return (0);
}
