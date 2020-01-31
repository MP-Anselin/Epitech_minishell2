/*
** basic_fonction.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2/include
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Thu Mar 23 17:10:46 2017 Anselin Mackendy-pierre
** Last update Wed Apr 26 15:16:01 2017 Anselin Mackendy-pierre
*/

#ifndef		_BASIC_FONCTION_H_
# define	_BASIC_FONCTION_H_
#include	"stock_tab.h"
#include	"unistd.h"

void		init_count(int *count, int nbr);
void		my_exit();
void		my_puttab(char **str);
char		*my_strcat(char *dest, char *src);
int		my_strlen(char *str);
int		my_strcmp(char *str, char *check);
int		check_env_cd(char *line, char **wordtab, char **cp_env);
int		usr_bin(char *coammand, char **tab, char **cp_env, pid_t *pid);
int		puterror(char *str);
int		display_str(int nbr, char *str);
void		free_tab(char **tab);

#endif		/* BASIC_FONCTION_H_ */
