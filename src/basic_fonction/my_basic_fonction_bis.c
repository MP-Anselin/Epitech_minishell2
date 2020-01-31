/*
** my_basic_fonction_bis.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/basic_fonction
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Tue Apr 11 20:26:27 2017 Anselin Mackendy-pierre
** Last update Tue Apr 18 13:04:25 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>

#include	"basic_fonction.h"
#include	"my_basic_fonction.h"

char		**my_sp_stock()
{
  char		**stock;
  int		y;

  y = 0;
  stock = malloc(sizeof(char*) * 5);
  if (stock == NULL)
    return (NULL);
  stock[0] = my_simp_strcat("<");
  stock[1] = my_simp_strcat("<<");
  stock[2] = my_simp_strcat(">");
  stock[3] = my_simp_strcat(">>");
  stock[4] = NULL;
  while (y != 4)
    {
      if (stock[y] == NULL)
	return (NULL);
      y++;
    }
  return (stock);
}

int		display_str(int nbr, char *str)
{
  int		len;

  len = my_strlen(str);
  write(1, str, len);
  if (nbr != 0)
    free(str);
  return (1);
}

int		puterror(char *str)
{
  int		len;

  len = my_strlen(str);
  write(1, str, len);
  return (1);
}

void		promt(char *user)
{
  if (user != NULL)
    display_str(0, user);
  display_str(0, "$>");
}
