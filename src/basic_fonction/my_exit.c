/*
** my_exit.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/basic_fonction
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr 11 18:12:33 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:55:25 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"basic_fonction.h"
#include	"my_pipes.h"

void		free_pipes(t_info_pipes *pip, char **str)
{
  free_tab(str);
  free(pip->in);
  free(pip->out);
  free(pip);
}

void		free_tab(char **tab)
{
  int		y;

  y = 0;
  while (tab[y] != NULL)
    {
      free(tab[y]);
      y++;
    }
  free(tab);
}

void		my_exit(int nbr, t_stock_tab *tab, char *user, int val_return)
{
  free(user);
  free_tab(tab->copy_env);
  free(tab);
  if (nbr == 1)
    write(1, "exit", 4);
  write(1, "\n", 1);
  exit(val_return);
}

int		exit_error(char *str)
{
  write(1, str, my_strlen(str));
  return (84);
}
