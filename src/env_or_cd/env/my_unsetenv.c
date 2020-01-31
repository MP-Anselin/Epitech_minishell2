/*
** my_unsetenv.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/env
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Thu Mar 23 16:40:13 2017 Anselin Mackendy-pierre
** Last update Tue Apr 11 23:12:01 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	"env.h"
#include	"strwordtab.h"
#include	"my_malloc.h"
#include	"basic_fonction.h"
#include	"my_basic_fonction.h"

int	my_check_n_char(char *cp_env, char *line)
{
  int	x;
  int	check;
  int	len;

  x = 0;
  check = 0;
  len = 0;
  while (cp_env[len] != '=')
    len++;
  while ((cp_env[x] != '=' && cp_env[x] != '\0') && line[x] != '\0')
    {
      if (cp_env[x] == line[x])
	check++;
      x++;
    }
  if (check == len)
    return (1);
  return (0);
}

int	check_search(char **cp_env, char *line)
{
  int	y;

  y = 0;
  while (cp_env[y] != NULL)
    {
      if (my_check_n_char(cp_env[y], line) == 1)
	return (y);
      y++;
    }
  return (-1);
}

char	**sup_line(char **cp_env, char *line)
{
  int	count[2];
  int	jump_line;
  char	**str;

  init_count(count, 2);
  jump_line = check_search(cp_env, line);
  if (jump_line == -1)
    return (cp_env);
  while (cp_env[count[2]] != NULL)
    count[2]++;
  str = my_ymalloc(jump_line);
  while (cp_env[count[0]] != NULL)
    {
      if (count[0] != jump_line)
	{
	  str[count[1]] = my_simp_strcat(cp_env[count[0]]);
	  count[1]++;
	}
      count[0]++;
    }
  str[count[1]] = NULL;
  return (str);
}

char	**my_unsetenv(char **cp_env, char *line)
{
  char	*src;
  char	**stock;
  char	**str_sup;
  int	var;
  int	i;

  i = 0;
  stock = cp_env;
  var = line_check_nbr_arg(line);
  if (var > 1)
    {
      str_sup = the_strwordtab(line, ' ');
      while (str_sup[i] != NULL)
	stock = sup_line(stock, str_sup[i++]);
      return (stock);
    }
  src = cut_str(line, var, 1);
  stock = sup_line(cp_env, src);
  return (stock);
}
