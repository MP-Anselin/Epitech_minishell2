/*
** my_basic_fonction.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/basic_fonction
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu Mar 23 16:23:53 2017 Anselin Mackendy-pierre
** Last update Tue Apr 11 23:29:03 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>

#include	"basic_fonction.h"
#include	"my_malloc.h"

int		my_nstrcmp(char *str, char *check)
{
  int		i;
  int		x;
  int		len;

  i = 0;
  x = 0;
  if (str == NULL || check == NULL)
    return (1);
  len = my_strlen(str);
  while (str[i] != '\0' && check[i] != '\0')
    {
      if (check[i] == str[i])
	x++;
      i++;
    }
  if (x == len)
    return (0);
  return (1);
}

int		my_tablen(char **strstr)
{
  int		y;

  y = 0;
  if (strstr[0] != NULL)
    while (strstr[y] != NULL)
      y++;
  return (y);
}

char		*my_simp_strcat(char *dest)
{
  char		*str;
  int		var;
  int		i;

  i = 0;
  var = my_strlen(dest);
  str = my_xmalloc(var);
  if (str != NULL && dest != NULL)
    while (dest[i] != '\0')
      {
	str[i] = dest[i];
	i++;
      }
  str[i] = '\0';
  return (str);
}

char		**my_strstrcat(char **dest, char *src)
{
  int		count[2];
  char		**str;

  init_count(count, 2);
  while (dest[count[1]] != NULL)
    count[1]++;
  str = my_ymalloc(count[1] + 1);
  count[1] = 0;
  if (dest != NULL)
    while (dest[count[0]] != NULL)
      {
	str[count[0]] = my_simp_strcat(dest[count[0]]);
	count[0]++;
      }
  if (src != NULL)
    while (src[count[1]] != '\0')
      {
	str[count[0]] = my_simp_strcat(src);
	count[1]++;
      }
  str[count[0] + 1] = NULL;
  return (str);
}

int		check_nbr_spchar(char *str, char c)
{
  int		x;
  int		nbr;

  x = 0;
  nbr = 0;
  while (str[x] != '\0')
    {
      if (str[x] == c)
	nbr++;
      x++;
    }
  return (nbr);
}
