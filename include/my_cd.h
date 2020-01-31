/*
** my_cd.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/include
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Sat Mar 25 15:09:29 2017 Anselin Mackendy-pierre
** Last update Mon Mar 27 19:25:36 2017 Anselin Mackendy-pierre
*/

#ifndef		MY_CD_H_
# define	MY_CD_H_

#include	"stock_tab.h"

int		my_cd(char **line, char **cp_env);
char		*search_road(char **cp_env, char *name);

#endif		/* MY_CD_H_ */
