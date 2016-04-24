##
## Makefile for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
##
## Made by vincent mesquita
## Login   <mesqui_v@epitech.net>
##
## Started on  Sun Apr 17 01:55:36 2016 vincent mesquita
## Last update Sun Apr 24 22:52:15 2016 Vincent Florian
##

NAME		=	lem_in

NAME_SERVER	=	visu_hex

NAME_CLIENT	=	client_visu

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra -I../inc -g3

LIB		=	-L/home/${USER}/.froot/lib	\
			-llapin -lsfml-audio		\
			-lsfml-graphics -lsfml-window	\
			-lsfml-system -lstdc++ -ldl -lm

SRCS		=	../Basics/my_putchar.c		\
			../Basics/my_putstr.c		\
			../Basics/my_puterror.c		\
			../Basics/my_put_nbr.c		\
			../Basics/my_strlen.c		\
			../Basics/my_strcpy.c		\
			../Basics/my_strcomp.c		\
			../Basics/my_getnbr.c		\
			../Basics/my_strcat_char.c	\
			../Basics/my_str_to_wordtab.c	\
			../Basics/my_free_wordtab.c	\
			../Basics/my_show_wordtab.c	\
			../Basics/my_wordtab_len.c	\
			../gnl/get_next_line.c		\
			../gnl/gnl2.c			\
			../gnl/gnl_use.c		\
			src/main.c			\
			../src/there_is_dash.c		\
			../src/my_nan.c			\
			../src/my_way.c			\
			../src/find_my_ways.c		\
			../src/my_ways_list.c		\
			../src/free_leminfo.c		\
			../src/my_epure_str.c		\
			../src/my_init_leminfo.c	\
			../src/my_fill_room_list.c	\
			../src/my_start_and_end.c	\
			../src/my_add_links.c		\
			../src/my_errors.c		\
			../src/is_a_comment.c		\
			../src/print_my_move.c		\
			../src/parser.c

OBJS		=	$(SRCS:.c=.o)


SRCS_SERV	=	src/server/server.c		\
			src/server/send_order.c		\
			src/server/treat_data.c		\
			../Basics/my_putchar.c		\
			../Basics/my_putstr.c		\
			../Basics/my_puterror.c		\
			../Basics/my_put_nbr.c		\
			../Basics/my_strlen.c		\
			../Basics/my_strcpy.c		\
			../Basics/my_strcomp.c		\
			../Basics/my_getnbr.c		\
			../Basics/my_strcat_char.c	\
			../Basics/my_str_to_wordtab.c	\
			../Basics/my_free_wordtab.c	\
			../Basics/my_show_wordtab.c	\
			../Basics/my_wordtab_len.c	\
			../Basics/get_next_line.c	\
			src/common_net.c		\
			../src/there_is_dash.c		\
			../src/my_nan.c			\
			../src/free_leminfo.c		\
			../src/my_epure_str.c		\
			../src/my_init_leminfo.c	\
			../src/my_fill_room_list.c	\
			../src/my_start_and_end.c	\
			../src/my_add_links.c		\
			../src/my_errors.c		\
			../src/is_a_comment.c		\
			src/server/parser.c

OBJS_SERV	=	$(SRCS_SERV:.c=.o)


SRCS_CLIENT	=	../Basics/my_putchar.c		\
			../Basics/my_putstr.c		\
			../Basics/my_puterror.c		\
			../Basics/my_put_nbr.c		\
			../Basics/my_strlen.c		\
			../Basics/my_strcpy.c		\
			../Basics/my_strcomp.c		\
			../Basics/my_getnbr.c		\
			../Basics/my_strcat_char.c	\
			../Basics/my_str_to_wordtab.c	\
			../Basics/my_free_wordtab.c	\
			../Basics/my_show_wordtab.c	\
			../Basics/my_wordtab_len.c	\
			../Basics/get_next_line.c	\
			src/client/tekpixel.c		\
			src/client/my_tektext.c		\
			src/client/display_client.c	\
			src/client/display_sprite.c	\
			src/client/display_client_bis.c	\
			src/client/client.c		\
			src/common_net.c

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_SERV) $(OBJS_CLIENT) $(OBJS)
	$(CC) -o $(NAME_SERVER) $(OBJS_SERV)
	$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIB)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_SERV) $(OBJS_CLIENT) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
