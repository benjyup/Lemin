##
## Makefile for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
##
## Made by vincent mesquita
## Login   <mesqui_v@epitech.net>
##
## Started on  Sun Apr 17 01:55:36 2016 vincent mesquita
## Last update Wed Apr 20 15:03:44 2016 vincent mesquita
##

NAME	=	lem_in

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -I./inc -g3

SRCS	=	./Basics/my_putchar.c		\
		./Basics/my_putstr.c		\
		./Basics/my_puterror.c		\
		./Basics/my_put_nbr.c		\
		./Basics/my_strlen.c		\
		./Basics/my_strcpy.c		\
		./Basics/my_strcomp.c		\
		./Basics/my_getnbr.c		\
		./Basics/my_strcat_char.c	\
		./Basics/my_str_to_wordtab.c	\
		./Basics/my_free_wordtab.c	\
		./Basics/my_show_wordtab.c	\
		./Basics/my_wordtab_len.c	\
		./Basics/get_next_line.c	\
		./src/main.c			\
		./src/there_is_dash.c		\
		./src/my_nan.c			\
		./src/my_way.c			\
		./src/free_leminfo.c		\
		./src/my_epure_str.c		\
		./src/my_init_leminfo.c		\
		./src/my_fill_room_list.c	\
		./src/my_start_and_end.c	\
		./src/my_add_links.c		\
		./src/recur_path.c		\
		./src/find_way.c		\
		./src/my_errors.c		\
		./src/is_a_comment.c		\
		./src/parser.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
