/*
** clean_str.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/basic_fonction
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr  4 16:49:55 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:39:55 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>

#include	"my_malloc.h"
#include	"basic_fonction.h"

char		*increment_start(char *str, char c)
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
  stock = my_xmalloc(count);
  while (str[x] != '\n' && str[x] != '\0')
    stock[i++] = str[x++];
  stock[i] = '\0';
  return (stock);
}

int		nbr_escape(char *str, char c, int *x, char *stock)
{
  while ((str[x[0]] == c || str[x[0]] == ' ' || str[x[0]] == '\t') &&
	 (str[x[0]] != '\n' && str[x[0]] != '\0'))
    x[0]++;
  if ((str[x[0]] == '\n' || str[x[0]] == '\0'))
    {
      stock[x[1]] = '\0';
      return (1);
    }
  else
    {
      stock[x[1]] = ' ';
      x[1]++;
    }
  return (0);
}

int		check_escape(char *str, char c)
{
  int		i;
  int		esc;

  i = 0;
  esc = 1;
  while (str[i] != '\n' && str[i] != '\0')
    {
      if ((str[i] == c || str[i] == ' ' || str[i] == '\t') &&
	  (str[i + 1] == c || str[i + 1] == ' ' || str[i + 1] == '\t') &&
	  (str[i + 1] != '\n' || str[i] != '\0'))
	{
	  if (esc > 0)
	    esc--;
	}
      esc++;
      i++;
    }
  return (esc);
}

char		*clean_str(char *str, char c)
{
  int		x[2];
  int		var;
  char		*stock;

  init_count(x, 2);
  var = check_escape(str, c );
  stock = my_xmalloc(var + 1);
  if (str[0] == c || str[0] == '\t' || str[0] == ' ')
    str = increment_start(str, c);
  while (str[x[0]] != '\n' && str[x[0]] != '\0')
    {
      if (str[x[0]] == c || str[x[0]] == ' ' || str[x[0]] == '\t')
	if (nbr_escape(str, c, x, stock) == 1)
	  {
	    free(str);
	    return (stock);
	  }
      stock[x[1]] = str[x[0]];
      x[1]++;
      x[0]++;
    }
  stock[x[1]] = '\0';
  free(str);
  return (stock);
}
