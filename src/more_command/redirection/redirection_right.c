/*
** rediction_right.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/more_command/redirection
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr 18 14:31:55 2017 Anselin Mackendy-pierre
** Last update Tue May  9 12:12:12 2017 Anselin Mackendy-pierre
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#include	"basic_fonction.h"

int		dual_redi_right(char *name)
{
  int		fd;

  fd = open(name, O_TRUNC | O_CREAT | O_WRONLY | O_APPEND, 0644);
  if (fd == -1)
    puterror("error open file\n");
  return (fd);
}

int		simple_redi_right(char *name)
{
  int		fd;

  fd = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0644);
  if (fd == -1)
    puterror("error open file\n");
  return (fd);
}

int		redirection_right(int check, char *name)
{
  if (check == 2)
    return (simple_redi_right(name));
  else
    return (dual_redi_right(name));
  return (0);
}
