##
## Makefile for  in /home/M-P.anselin/delivery/PSU/PSU_2016_tetris
##
## Made by Anselin Mackendy-pierre
## Login   <M-P.anselin@epitech.net>
##
## Started on  Wed Mar  8 11:58:07 2017 Anselin Mackendy-pierre
## Last update Tue May  9 14:39:53 2017 Anselin Mackendy-pierre
##


NAME	=	mysh

SRCS	=	src/main.c						\
		src/basic_fonction/my_get_next_line.c			\
		src/basic_fonction/basic_fonction.c			\
		src/basic_fonction/my_basic_fonction_bis.c		\
		src/basic_fonction/my_basic_fonction.c			\
		src/basic_fonction/my_str_to_wordtab.c			\
		src/basic_fonction/clean_str.c				\
		src/basic_fonction/my_exit.c				\
		src/basic_fonction/my_malloc.c				\
		src/check_error/my_setenv_error.c			\
		src/check_error/check_line_enter.c			\
		src/usr_bin/usr_bin.c					\
		src/env_or_cd/env/my_setenv.c				\
		src/env_or_cd/env/my_unsetenv.c				\
		src/env_or_cd/env/copy_env.c				\
		src/env_or_cd/my_cd/my_cd.c				\
		src/env_or_cd/my_cd/search_name.c			\
		src/env_or_cd/check_env_cd.c				\
		src/more_command/more_command.c				\
		src/more_command/pipe/my_pipe.c				\
		src/more_command/pipe/exec_pipe.c			\
		src/more_command/redirection/check_redir.c		\
		src/more_command/redirection/my_dup.c			\
		src/more_command/redirection/redirection_left.c		\
		src/more_command/redirection/redirection_right.c	\
		src/my_exec/my_execve.c


OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I include

CC	=	gcc -g -W -Wall -pedantic

all:	$(NAME)

$(NAME):		$(OBJS) $(LIB)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
