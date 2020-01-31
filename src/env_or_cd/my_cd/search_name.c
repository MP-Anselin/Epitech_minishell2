/*
** pwd.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/my_cd
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Sat Mar 25 14:21:34 2017 Anselin Mackendy-pierre
** Last update Tue Apr 11 23:20:51 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>

#include	"my_malloc.h"
#include	"stock_tab.h"
#include	"basic_fonction.h"
#include	"my_basic_fonction.h"

char		*cut_n_char(char *str)
{
  char	*stock;
  int	x;
  int	i;
  int	len;

  x = 0;
  i = 0;  
  while (str[x] != '=' && str[x] != '\0')
    x++;
  len =  my_strlen(str);
  stock = my_xmalloc(len - x);
  if (stock == NULL)
    return (NULL);
  x = x + 1;
  while (str[x] != '\0')
    {
      stock[i] = str[x];
      i++;
      x++;
    }
  stock[i] = '\0';
  return (stock);
}

int		search_name(char **cp_env, char *name)
{
  int	y;

  y = 0;
  while (cp_env[y] != NULL)
    {
      if (my_nstrcmp(name, cp_env[y]) == 0)
	return (y);
      y++;
    }
  return (-1);
}

char		*search_road(char **cp_env, char *name)
{
  char	*road;
  int	y;

  if ((y = search_name(cp_env, name)) == -1)
    return (NULL);
  road = cut_n_char(cp_env[y]);
  return (road);
}
