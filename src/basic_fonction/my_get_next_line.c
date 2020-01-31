/*
** jenaimare.c for  in /home/M-P.anselin/delivery/CPE_2016/CPE_2016_getnextline
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sun Jan 15 14:03:36 2017 Anselin Mackendy-pierre
** Last update Fri May  5 17:38:36 2017 Anselin Mackendy-pierre
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	"get_next_line.h"

char	*re_alloc(char *stock, int count)
{
  char *str;
  int	x;
  int	i;

  x = 0;
  i = 0;
  str = malloc(sizeof(char) * ((READ_SIZE * count) + 1));
  if (str == NULL)
    {
      return (NULL);
    }
  str[READ_SIZE + count] = '\0';
    for (int x = 0; x <  count; ++x)
    {
      str[i] = stock[x];
      i++;
      x++;
    }
  free(stock);
  return (str);
}

char	get_one_read(const int fd)
{
  static char buffer[READ_SIZE];
  static int check_count;
  static int my_count;
  char save_c;

  if (check_count == 0)
    {
      check_count = read(fd, buffer, READ_SIZE);
      buffer[check_count] = '\0';
      my_count = 0;
    }
  if  (my_count != READ_SIZE)
    {
      save_c = buffer[my_count];
      my_count++;
      check_count--;
      return (save_c);
    }
  return (0);
}

char	*get_next_line(const int fd)
{
  int	count;
  char	save_c;
  char	*stock_line;

  count = 0;
  stock_line = malloc(sizeof(char) * (READ_SIZE + 1));
  if (stock_line == NULL || fd == -1)
    return (NULL);
  save_c = get_one_read(fd);
  while (save_c != '\n' && save_c != '\0')
    {
      stock_line[count] = save_c;
      save_c = get_one_read(fd);
      count++;
      if ((count % (READ_SIZE + 1)) == 0)
	stock_line = re_alloc(stock_line, count);
    }
  stock_line[count] = '\0';
  if (save_c == '\0' && stock_line[0] == '\0')
    {
      free(stock_line);
      return (0);
    }
  return (stock_line);
}
