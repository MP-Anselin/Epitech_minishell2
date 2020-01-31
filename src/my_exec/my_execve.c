/*
** my_execve.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/my_exec
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Mon Mar 27 16:13:49 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:28:03 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"basic_fonction.h"
#include	"strwordtab.h"
#include	"my_basic_fonction.h"
#include	"my_malloc.h"

int		search_path(char **cp_env)
{
  int		y;
  int		var;

  y = 0;
  while (cp_env[y] != NULL)
    {
      var = my_nstrcmp("PATH=", cp_env[y]);
      if (var == 0)
	return (y);
      y++;
    }
  return (-1);
}

char		*change_str(char *command, char *the_path)
{
  int		len;
  char		*stock;
  char		*path;

  len = my_strlen(the_path);
  if (the_path[len - 1] != '/')
    stock = my_strcat(the_path, "/");
  path = my_strcat(stock, command);
  free(stock);
  return (path);
}

char		**change_path(char *command, char *the_path)
{
  char		**path;
  char		**new_path;
  int		y;

  y = 1;
  path = the_strwordtab(the_path, ':');
  new_path = my_ymalloc(my_tablen(path));
  new_path[0] = my_simp_strcat(command);
  while (path[y] != NULL)
    {
      new_path[y] = change_str(command, path[y]);
      y++;
    }
  new_path[y] = NULL;
  free_tab(path);
  return (new_path);
}

char		*command_not_found(char *cmd, char **new_path, int *val_return)
{
  *val_return = 1;
  display_str(0, cmd);
  display_str(0, ": Command not found\n");
  free_tab(new_path);
  return (NULL);
}

char	*check_access(char *command, char **path, char **env, int *val_return)
{
  char	**new_path;
  char	*stock;
  int	save_y;
  int	y;

  y = 0;
  save_y = search_path(env);
  if (save_y == -1)
    return (NULL);
  new_path = change_path(command, env[save_y]);
  while (new_path[y] != NULL)
    {
      if (access(new_path[y], F_OK) != -1)
	{
	  *val_return = 0;
	  stock = my_simp_strcat(new_path[y]);
	  free_tab(new_path);
	  return (stock);
	}
      y++;
    }
  return (command_not_found(path[0], new_path, val_return));
}
