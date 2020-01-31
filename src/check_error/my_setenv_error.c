/*
** my_setenv_error.c for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/src/check_error
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu Mar 23 16:47:15 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:33:19 2017 Anselin Mackendy-pierre
*/

#include	"env.h"
#include	"basic_fonction.h"
#include	"stock_tab.h"

int	line_check_nbr_arg(char *str)
{
  int	i;
  int	esp;

  i = 0;
  esp = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	  if (str[i] != '\0')
	    esp++;
	  i--;
	}
      i++;
    }
  return (esp);
}

int	check_line_arg(char *str)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(str);
  while ((str[i] != '\0' && str[i] >= 48 && str[i] <= 57) || str[i] == 32 ||
	 str[i] == 46 || (str[i] >= 65 && str[i] <= 90) ||
	 (str[i] >= 97 && str[i] <= 122))
    i++;
  if (i == len)
    return (0);
  return (1);
}

int	check_error_setenv(char *line, char **cp_env)
{
  int	var;

  var = line_check_nbr_arg(line);
  if (var == 1 || var == 2)
    {
      if ((check_line_arg(line)) == 0)
	cp_env = my_setenv(cp_env, line, var);
      else
	puterror("variable name must contain alphanumeric characters\n");
    }
  else if (var > 2)
    puterror("too many argurments\n");
  return (-1);
}
