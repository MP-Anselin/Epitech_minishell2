/*
** copy_env.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/env
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Tue Apr 11 17:59:12 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:47:28 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	"basic_fonction.h"
#include	"my_basic_fonction.h"
#include	"my_malloc.h"

char		**copy_env(char **env)
{
  char	**copy_env;
  int	len;
  int	x;
  int	y;

  y = 0;
  if (env == NULL)
    return (NULL);
  len = my_tablen(env);
  copy_env = my_ymalloc(len);
  while (env[y] != NULL)
    {
      x = 0;
      len = my_strlen(env[y]);
      copy_env[y] = my_xmalloc(len);
      while (env[y][x] != '\0')
	{
	  copy_env[y][x] = env[y][x];
	  x++;
	}
      copy_env[y][x] = '\0';
      y++;
    }
  copy_env[y] = NULL;
  return (copy_env);
}
