/*
** rediction_left.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/more_command/redirection
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Sun Apr  9 22:49:25 2017 Anselin Mackendy-pierre
** Last update Tue May  9 10:30:53 2017 Anselin Mackendy-pierre
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>

#include	"basic_fonction.h"
#include	"get_next_line.h"

int		simple_redi_left(char *name)
{
  int		fd;

  fd = open(name, O_RDONLY);
  if (fd == -1)
    puterror("error open file\n");
  return (fd);
}

int		dual_redi_left(char *name)
{
  int		var;
  char		*buffer;

  var = 0;
  buffer = NULL;
  while (var == 0 && my_strcmp(name, buffer) == 1)
    {
      write(1, "?", 1);
      buffer = get_next_line(0);
      if (buffer == NULL)
	{
	  free(buffer);
	  var = 1;
	}
    }
  return (-10);
}

int		redirection_left(int check, char *name)
{
  if (check == 0)
    return (simple_redi_left(name));
  else
    return (dual_redi_left(name));
  return (0);
}
