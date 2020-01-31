/*
** stock_tab.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/include
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu Mar 23 17:04:51 2017 Anselin Mackendy-pierre
** Last update Wed Apr 26 15:09:47 2017 Anselin Mackendy-pierre
*/

#ifndef		_STOCK_TAB_H_
# define	_STOCK_TAB_H_

typedef struct	S_stock_tab
{
  char		**wordtab;
  char		**sp_char;
  char		**copy_env;
  char		*line;
}		t_stock_tab;

# endif		/* !STOCK_TAB_H */
