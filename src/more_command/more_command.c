/*
** more_command.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/more_command
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Sun Mar 26 08:41:30 2017 Anselin Mackendy-pierre
** Last update Fri May  5 16:55:39 2017 Anselin Mackendy-pierre
*/

#include	"more_command.h"

int		free_more_command(char *cmd, char *tock, char **stock, int nbr)
{
  free(tock);
  free(cmd);
  free_tab(stock);
  return (nbr);
}
char		*sup_char(char *str, char c)
{
  int		i;
  int		x;
  int		len;
  char		*stock;

  i = 0;
  len = 0;
  if (str[0] == c)
    while (str[i] == c)
      i++;
  x = i;
  i = 0;
  while (str[len] != c && str[len] != '\0')
    len++;
  stock = my_xmalloc(len);
  while (str[x] != c && str[x] != '\0')
    {
      stock[i] = str[x];
      x++;
      i++;
    }
  stock[x] = '\0';
  return (stock);
}

int		exec_sp_char(t_stock_tab *tab, char *str, int *val_return)
{
  char		**stock;
  int		nbr_pipe;
  char		*tock;
  char		*cmd;

  tock = clean_str(str, ' ');
  stock = the_strwordtab(tock, ' ');
  stock[0] = sup_char(stock[0], ' ');
  if ((nbr_pipe = check_nbr_spchar(str, '|')) > 0)
    my_pipes(the_strwordtab(str, '|'), nbr_pipe, tab->copy_env, val_return);
  else if (check_line_enter(str) != 1 &&
	   check_env_cd(str, stock, tab->copy_env) != 0 && nbr_pipe == 0)
    {
      cmd = check_access(stock[0], stock, tab->copy_env, val_return);
      if (cmd != NULL)
	val_return[1] = usr_bin(cmd, stock, tab->copy_env, val_return);
      if (val_return[1] == 84)
	return (free_more_command(cmd, tock, stock, 84));
    }
  return (free_more_command(cmd, tock, stock, 0));
}

int		more_command(t_stock_tab *tab, int *val_return)
{
  int		y;
  int		var;

  y = 0;
  var = 0;
  tab->sp_char = the_strwordtab(tab->line, ';');
  if (tab->sp_char == NULL)
    return (84);
  while (tab->sp_char[y] != NULL)
    {
      var = exec_sp_char(tab, tab->sp_char[y], val_return);
      if (var == 84)
	return (84);
      y++;
    }
  free_tab(tab->sp_char);
  return (0);
}
