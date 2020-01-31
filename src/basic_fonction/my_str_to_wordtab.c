/*
** my_str_to_wordtab.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/basic_fonction
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Mar 28 14:46:19 2017 Anselin Mackendy-pierre
** Last update Thu Apr 13 21:28:25 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>

#include	"my_malloc.h"
#include	"basic_fonction.h"

int		nbr_char(char *str, char c)
{
  int		check;
  int		x;
  int		i;

  x = 0;
  i = 0;
  check = 0;
  while (str[x] != '\0')
    {
      if (str[x] == c)
	{
	  i = x;
	  while (str[i] == c && str[i] != '\0' && str[i] != '\n')
	    i++;
	  if (str[i] != '\n' && str[i] != '\0')
	    {
	      check++;
	      x = i - 1;
	    }
	  else
	    return (check);
	}
      x++;
    }
  return (check);
}

char		*increment_zero(char *str, char c)
{
  char		*stock;
  int		len;
  int		count;
  int		x;
  int		i;

  i = 0;
  count = 0;
  len = 0;
  while (str[len] == c || str[len] == '\t' || str[len] == ' ' )
    len++;
  x = len;
  while (str[len] != '\n' && str[len] != '\0')
    {
      count++;
      len++;
    }
  stock = my_xmalloc(count + 1);
  if (stock == NULL)
    return (stock);
  while (str[x] != '\n' && str[x] != '\0')
    stock[i++] = str[x++];
  stock[i] = '\0';
  return (stock);
}

char		*increment(char *str, char c, int *axe)
{
  char		*stock;

  while (str[axe[0]] == c || str[axe[0]] == ' ' || str[axe[0]] == '\t')
    axe[0]++;
  if (str[axe[0]] == '\n' || str[axe[0]] == '\0')
    {
      stock = NULL;
      return (stock);
    }
  stock = my_xmalloc(axe[0] + 1);
  return (stock);
}

char		*fill_stock(char *str, char c, char *stock, int *axe)
{
  int		len;
  int		i;

  i = 0;
  len = axe[0];
  if (str[axe[0]] == c || str[axe[0]] == '\t' || str[axe[0]] == ' ')
    {
      stock = increment(str, c, axe);
      if (stock == NULL)
	return (stock);
    }
  while (str[len] != c && str[len] != '\n' && str[len] != '\0')
    len++;
  stock = my_xmalloc(len + 2);
  while (str[axe[0]] != c && str[axe[0]] != '\n' && str[axe[0]] != '\0')
    {
      stock[i] = str[axe[0]];
      i++;
      axe[0]++;
    }
  if (str[axe[0]] == '\n' || str[axe[0]] == '\0')
    axe[2] = -1;
  stock[i] = '\0';
  return (stock);
}

char		**the_strwordtab(char *str, char c)
{
  char		**stock;
  int		axe[3];
  int		var;

  init_count(axe, 3);
  if (str[0] == c || str[0] == '\t' || str[0] == ' ')
    str = increment_zero(str, c);
  var = nbr_char(str, c);
  stock = my_ymalloc(var + 2);
  if (stock == NULL)
    return (NULL);
  while (str[axe[0]] != '\n' && str[axe[0]] != '\0')
    {
      if (axe[2] == -1)
	{
	  stock[axe[1]] = NULL;
	  return (stock);
	}
      stock[axe[1]] = fill_stock(str, c, stock[axe[1]], axe);
      axe[1]++;
    }
  stock[axe[1]] = NULL;
  return (stock);
}
