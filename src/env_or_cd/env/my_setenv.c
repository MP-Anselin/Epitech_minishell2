/*
** my_setenv.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/env
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Thu Mar 23 16:33:54 2017 Anselin Mackendy-pierre
** Last update Wed Apr 12 13:43:11 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	"my_basic_fonction.h"
#include	"basic_fonction.h"
#include	"my_malloc.h"
#include	"env.h"

char	*setenv_new_line(char *str, int *count)
{
  char	*new_line;

  count[3] = count[0];
  while (str[count[3]] != ' ' || str[count[3]] != '\t')
    count[3]++;
  count[2] = count[3];
  while (str[count[2]] == ' ' || str[count[2]] == '\t')
    count[2]++;
  count[1] = count[2];
  while (str[count[2]])
    {
      count[2]++;
      count[4]++;
    }
  new_line = my_xmalloc(count[3] + count[4] + 1);
  count[3] = count[0];
  while (str[count[3]] != ' ' || str[count[3]] != '\t')
    {
      new_line[count[3]] = str[count[3]];
      count[3]++;
    }
  new_line[count[3]] = '=';
  while (str[count[2]] != '\0')
    new_line[count[3]++] = str[count[2]++];
  return (new_line);
}

char	*check_setenv_line(char *str)
{
  int	count[5];
  char	*new_line;

  init_count(count, 5);
  while (str[count[0]] == ' ' || str[count[0]] == '\t')
    count[0]++;
  count[1] = count[0];
  while (str[count[1]] != '\0')
    {
      if (str[count[1]] == ' ' || str[count[1]] == '\t')
	{
	  while (str[count[1]] == ' ' || str[count[1]] == '\t')
	    count[1]++;
	  count[2]++;
	}
      count[1]++;
    }
  if (count[2] == 1)
    return (str);
  new_line = setenv_new_line(str, count);
  return (new_line);
}

char	*add_egale(char *str, int *count, int var, int nbr)
{
  char	*new_str;

  new_str = my_xmalloc(count[2] + 1);
  while (str[count[0]] != '\0')
    {
      if ((var >= 2 && str[count[0]] == ' ') || str[count[0]] == '\t')
	{
	  while (str[count[0]] == ' ' || str[count[0]] == '\t')
	    count[0]++;
	  if (count[0] != count[1] && nbr == 0)
	    new_str[count[3]++] = '=';
	  else if (nbr != 0)
	    new_str[count[3]++] = ' ';
	}
      new_str[count[3]++] = str[count[0]++];
    }
  if (var == 1 && nbr == 0)
    {
      new_str[count[3]] = '=';
      new_str[count[3]+ 1] = '\0';
      return (new_str);
    }
  new_str[count[3]] = '\0';
  return (new_str);
}

char	*cut_str(char *str, int var, int nbr)
{
  int	count[4];
  char	*new_str;

  init_count(count, 4);
  while (str[count[0]] == ' ' || str[count[0]] == '\t')
    count[0]++;
  while (str[count[0]] != ' ' || str[count[0]] == '\t')
    count[0]++;
  while (str[count[0]] == ' ' || str[count[0]] == '\t')
    count[0]++;
  while (str[count[1]] != '\0')
    count[1]++;
  count[2] = count[1] - count[0];
  new_str = add_egale(str, count, var, nbr);
  return (new_str);
}

char	**my_setenv(char **cp_env, char *str, int var)
{
  char	*src;
  char	**stock;

  src = cut_str(str, var, 0);
  if ((check_search(cp_env, src)) != -1)
    return (cp_env);
  stock = my_strstrcat(cp_env, src);
  return (stock);
}
