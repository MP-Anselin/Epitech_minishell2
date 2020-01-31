/*
** redirection.h for  in /home/M-P.anselin/delivery/PSU/PSU_2016_minishell2
**
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
**
** Started on  Mon May  8 11:21:05 2017 Anselin Mackendy-pierre
** Last update Mon May  8 11:21:06 2017 Anselin Mackendy-pierre
*/

#ifndef		REDIRECTION_H_
# define	REDIRECTION_H_

int		check_redir(char **tab, char **cp_env, int *val_retrn, int nbr);
void		my_dup_redir(int *fd);
int		redirection_left(int check, char *name);
int		redirection_right(int check, char *name);

#endif		/* !REDIRECTION_H_*/
