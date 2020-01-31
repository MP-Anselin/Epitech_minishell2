/*
** my_dup.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/more_command/redirection
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue May  9 11:43:00 2017 Anselin Mackendy-pierre
** Last update Tue May  9 12:11:46 2017 Anselin Mackendy-pierre
*/
#include	<unistd.h>

#include	"basic_fonction.h"

void		my_dup_redir(int *fd)
{
  if (dup2(fd[0], 1) == -1)
    puterror("dup2 error\n");
  if (fd[1] != 0)
    {
      if (dup2(fd[0], 0) == -1)
	puterror("dup2 error\n");
    }
  if (dup2(fd[0], 2) == -1)
    puterror("dup2 error\n");
  close(fd[0]);
}
