/*
** basic_fonction.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/basic_fonction
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu Mar 23 15:02:17 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:39:18 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>

#include	"basic_fonction.h"
#include	"my_malloc.h"

void		my_puttab(char **str)
{
  int		i;

  i = 0;
  while (str[i] != NULL)
    {
      display_str(0, str[i]);
      write(1, "\n", 1);
      i++;
    }
}

void		init_count(int *count, int nbr)
{
  int		i;

  i = 0;
  while (i <= nbr)
    {
      count[i] = 0;
      i++;
    }
}

int		my_strlen(char *str)
{
  int		len;

  len = 0;
  if (str != NULL)
    while (str[len] != '\0')
      len++;
  return (len);
}

char		*my_strcat(char *dest, char *src)
{
  int		count;
  int		len;
  int		var[2];
  char		*str;

  count = 0;
  len = 0;
  var[0] = my_strlen(dest);
  var[1] = my_strlen(src);
  str = my_xmalloc(var[0] + var[1]);
  if (dest != NULL)
    while (dest[len] != '\0')
      {
	str[len] = dest[len];
	len++;
      }
  if (src != NULL)
    while (src[count] != '\0')
      {
	str[len] = src[count];
	len++;
	count++;
      }
  str[len] = '\0';
  return (str);
}

int		my_strcmp(char *str, char *check)
{
  int		i;
  int		x;
  int		len[2];

  i = 0;
  x = 0;
  if (str == NULL || check == NULL)
    return (1);
  len[0] = my_strlen(str);
  len[1] = my_strlen(check);
  if (len[0] != len[1])
    return (1);
  while (str[i] != '\0' && check[i] != '\0')
    {
      if (check[i] == str[i])
	x++;
      i++;
    }
  if (x == len[0])
    return (0);
  return (1);
}
