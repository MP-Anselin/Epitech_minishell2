/*
** check_if_env_cd.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/env_or_cd
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr 11 19:53:37 2017 Anselin Mackendy-pierre
** Last update Mon Apr 24 15:36:00 2017 Anselin Mackendy-pierre
*/

#include	"check_error.h"
#include	"env.h"
#include	"basic_fonction.h"
#include	"my_basic_fonction.h"
#include	"stock_tab.h"
#include	"my_cd.h"

void		sp_init_count(int *var, char *line)
{
  var[0] = my_nstrcmp("setenv ", line);
  var[1] = line_check_nbr_arg(line);
  var[2] = my_strcmp("env", line);
  var[3] = my_strcmp("setenv", line);
  var[4] = my_nstrcmp("unsetenv ", line);
}

int		check_env_cd(char *line, char **wordtab, char **cp_env)
{
  int	var[5];
  int	check;

  sp_init_count(var, line);
  if (var[0] == 0 && var[1] != 0)
    check_error_setenv(line , cp_env);
  else if (var[2] == 0 || (var[3] == 0 && var[1] == 0))
    my_puttab(cp_env);
  else if (var[4] == 0)
    cp_env = my_unsetenv(cp_env, line);
  else if (var[0] != 0 && var[2] != 0 && var[3] != 0 && var[4] != 0)
    {
      check = my_cd(wordtab, cp_env);
      if (check == 0)
	return (0);
    }
  if (var[0] != 0 && (var[2] != 0 && var[3] != 0)
      && var[4] != 0 && check != 0)
    return (-1);
  return (0);
}
