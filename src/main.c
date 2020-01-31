/*
** main.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu Mar 23 16:07:26 2017 Anselin Mackendy-pierre
** Last update Tue May  9 12:15:37 2017 Anselin Mackendy-pierre
*/

#include	"my_main.h"

void		the_control_c()
{
  display_str(0, "\n$>");
}

int		check_other_fonctions(t_stock_tab *tab, int *val_rtrn)
{
  int		check[2];
  int		val;
  char		*cmd;

  cmd = NULL;
  check[0] = check_env_cd(tab->line, tab->wordtab, tab->copy_env);
  check[1] = check_redir(tab->wordtab, tab->copy_env, val_rtrn, 1);
  if (check[0] == 84 || check[1] == 84)
    return (84);
  else if (check[0] == -1 && check[1] == -1)
    cmd = check_access(tab->wordtab[0], tab->wordtab, tab->copy_env, val_rtrn);
  if (check[0] == -1 && check[1] == -1 && cmd != NULL)
    {
      val = usr_bin(cmd, tab->wordtab, tab->copy_env, val_rtrn);
      free(cmd);
      return (val);
    }

  return (0);
}

int		check_line_command(t_stock_tab *tab, int *val_return)
{
  char		**word_pipe;
  int		nbr_pipe;
  int		var;

  tab->line = clean_str(tab->line, ' ');
  tab->wordtab = the_strwordtab(tab->line, ' ');
  if (tab->wordtab == NULL)
    return (84);
  nbr_pipe = check_nbr_spchar(tab->line, '|');
  var = check_line_enter(tab->line);
  if (check_nbr_spchar(tab->line, ';') > 0 && var == 0)
    return (more_command(tab, val_return));
  else if (nbr_pipe > 0 && var == 0)
    {
      word_pipe = the_strwordtab(tab->line, '|');
      if (word_pipe == NULL)
	return (84);
      return (my_pipes(word_pipe, nbr_pipe, tab->copy_env, val_return));
    }
  else if (var == 0)
    return (check_other_fonctions(tab, val_return));
  return (0);
}

void		start(t_stock_tab *tab, char *user)
{
  int		val_return;

  val_return = 0;
  while (1 > 0)
    {
      signal(SIGINT, the_control_c);
      if (isatty(0) == 1)
	promt(user);
      tab->line = get_next_line(0);
      if (tab->line == NULL)
	my_exit(2, tab, user, val_return);
      if (my_strcmp("exit", tab->line) == 0)
	my_exit(1, tab, user, val_return);
      if (check_line_command(tab, &val_return) == 84)
	my_exit(0, tab, user, 84);
      free(tab->line);
      free_tab(tab->wordtab);
    }
}

int		main(int ac, char **av, char **env)
{
  t_stock_tab	*tab;
  char		*user;
  (void)	av;

  if (ac != 1)
    return (-1);
  tab = malloc(sizeof(t_stock_tab));
  if (tab == NULL)
    return (84);
  tab->wordtab = NULL;
  tab->sp_char = NULL;
  tab->copy_env = copy_env(env);
  if (tab->copy_env == NULL)
    exit_error("environment is NULL\n");
  user = search_road(tab->copy_env, "USER");
  start(tab, user);
  return (0);
}
