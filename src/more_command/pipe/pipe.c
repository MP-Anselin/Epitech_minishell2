/*
** my_pipe.c for  in /home/M-P.anselin/delivery/stock/PSU_2016_minishell2/src/more_command/pipe
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu May  4 14:27:26 2017 Anselin Mackendy-pierre
** Last update Tue May  9 16:21:25 2017 Anselin Mackendy-pierre
*/

#include	"my_pipes.h"

void	end_pipes(t_info_pipes *pip, int *i, int *fd_in, int *val_return)
{
  int	status;

  status = 0;
  wait(&status);
  if (WTERMSIG(status) == 11)
    {
      val_return[0] = 1;
      puterror("Segmentation fault (core dumped)\n");
    }
  close(pip->out[*i]);
  *fd_in = pip->in[*i];
}

void		my_dup(t_info_pipes *pip, int i, int fd_in)
{
  if (dup2(fd_in, 0) == -1)
    puterror("dup2 error\n");
  if ((i + 1) <= pip->max_pipe)
    if (dup2(pip->out[i], 1) == -1)
      puterror("dup2 error\n");
  close(pip->in[i]);
}

int		exec_pipes(t_info_pipes *pip, char **str,
			   char **cp_env, int *val_return)
{
  int		pid;
  int		i;
  int		fd_in;

  i = 0;
  fd_in = 0;
  while (i <= pip->max_pipe)
    {
      pid = fork();
      if (pid == -1)
	return (84);
      if (pid == 0)
	{
	  my_dup(pip, i, fd_in);
	  execve_pipe(str[i], cp_env, val_return);
	  exit(0);
	}
      else
	end_pipes(pip, &i, &fd_in, val_return);
      i++;
    }
  return (0);
}

int	init_pipes(t_info_pipes *pip, int nbr_pipe, int *val_return)
{
  int	i;
  int	fd[2];

  i = 0;
  pip->in = malloc(sizeof(int) * (nbr_pipe + 1));
  pip->out = malloc(sizeof(int) * (nbr_pipe + 1));
  pip->max_pipe = nbr_pipe;
  if (pip->in == NULL || pip->out == NULL)
    {
      *val_return = 84;
      display_str(1, "cant not malloc\n");
      return (84);
    }
  while (i <= nbr_pipe)
    {
      if (pipe(fd) == -1)
	{
	  *val_return = 1;
	  puterror("error for the pipes\n");
	}
      pip->in[i] = fd[0];
      pip->out[i] = fd[1];
      i++;
    }
  return (0);
}

int	my_pipes(char **str, int nbr_pipe, char **cp_env, int *val_return)
{
  t_info_pipes	*pip;
  int		val;

  val = 0;
  pip = malloc(sizeof(t_info_pipes));
  if (pip == NULL)
    {
      *val_return = 84;
      display_str(1, "cant not malloc\n");
      return (84);
    }
  if (init_pipes(pip, nbr_pipe, val_return) == 84)
    return (84);
  if (exec_pipes(pip, str, cp_env, val_return) == 84)
    val = 84;
  free_pipes(pip, str);
  return (val);
}
