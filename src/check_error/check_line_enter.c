/*
** check_line_enter.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/check_error
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sat Mar 25 19:37:18 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:32:12 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	"basic_fonction.h"
#include	"my_malloc.h"

char	*init_chare()
{
  char	*ch;

  ch = my_xmalloc(5);
  ch[0] = '>';
  ch[1] = '<';
  ch[2] = ';';
  ch[3] = '|';
  ch[4] = '\0';
  return (ch);
}

int	command_incorrect(char *ch)
{
  puterror("command incorret\n");
  free(ch);
  return (1);
}

int	check_char(char *str, char *ch, int size, int *x)
{
  x[2] = 0;
  while (x[2] <= size)
    {
      if ((str[x[0]] == '>' && str[x[0] + 1] == '>' && ch[x[1]] == '>')
	  && str[x[0] + 2] == ch[x[2]])
	return (1);
      else if (str[x[0]] == ch[x[1]] &&
	       (str[x[0]] == '<' && str[x[0] + 1] == '<') &&
	       str[x[0] + 2] == ch[x[2]])
	return (1);
      else if (str[x[0] + 1] != '<' && str[x[0] + 1] != '>' &&
	       str[x[0]] == ch[x[1]] && str[x[0] + 1] == ch[x[2]])
	return (1);
      x[2]++;
    }
  return (0);
}

int	check_char_zero(char *str, char *ch, int size, int *x)
{
  x[3] = 0;
  while (x[3] <= size)
    {
      if (x[0] == 0 && str[x[0]] == ch[x[3]])
	return (1);
      x[3]++;
    }
  return (0);
}

int	check_line_enter(char *str)
{
  int	x[3];
  int	size;
  char	*ch;

  ch = init_chare();
  size =  my_strlen(ch);
  init_count(x, 3);
  while (str[x[0]] != '\0')
    {
      x[1] = 0;
      if (check_char_zero(str, ch, size, x) == 1)
	return (command_incorrect(ch));
      while (x[1] <= size)
	{
	  if (str[x[0]] == ch[x[1]] && str[x[0] + 1] == ' ' &&
	      str[x[0] + 2] == ch[x[1]])
	    return (command_incorrect(ch));
	  if (check_char(str, ch, size,  x) == 1)
	    return (command_incorrect(ch));
	  x[1]++;
	}
      x[0]++;
    }
  free(ch);
  return (0);
}
