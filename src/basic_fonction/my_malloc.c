/*
** my_malloc.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/basic_fonction
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr 11 18:55:02 2017 Anselin Mackendy-pierre
** Last update Wed Apr 12 13:39:11 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	"my_exit.h"

char		**my_ymalloc(int len)
{
  char	**tab;

  len  += 1;
  tab = malloc(sizeof(char*) * len);
  if (tab == NULL)
    exit_error("Unable to malloc\n");
  return (tab);
}

char		*my_xmalloc(int len)
{
  char	*str;

  len  += 1;
  str = malloc(sizeof(char) * len);
  if (str == NULL)
    exit_error("Unable to malloc\n");
  return (str);
}
