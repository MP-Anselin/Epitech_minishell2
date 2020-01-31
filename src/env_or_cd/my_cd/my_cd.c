/*
** my_cd.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/my_cd
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Sat Mar 25 13:50:46 2017 Anselin Mackendy-pierre
** Last update Wed May  3 10:53:42 2017 Anselin Mackendy-pierre
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"my_cd.h"
#include	"stock_tab.h"
#include	"basic_fonction.h"
#include	"my_basic_fonction.h"

int		check_cd(char **line)
{
  int		var[3];

  var[3] = my_tablen(line);
  if (var[3] < 1)
    return (-1);
  var[0] = my_strcmp("--", line[1]);
  var[1] = my_strcmp("cd", line[0]);
  if ((var[0] == 0 || var[1] == 0) && var[3] == 1)
    return (1);
  else if (var[1] == 0 && var[3] > 1)
    return (2);
  return (0);
}

int		my_cd(char **line, char **cp_env)
{
  char		*home;
  int		check;

  home = search_road(cp_env, "HOME=");
  if (home != NULL)
    {
      check = check_cd(line);
      if (check == 1)
	{
	  chdir(home);
	  free(home);
	  return (0);
	}
      else if (check == 2)
	{
	  chdir(line[1]);
	  free(home);
	  return (0);
	}
    }
  free(home);
  return (1);
}
