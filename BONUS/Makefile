##
## Makefile for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
##
## Made by vincent mesquita
## Login   <mesqui_v@epitech.net>
##
## Started on  Sun Apr 17 01:55:36 2016 vincent mesquita
## Last update Thu Apr 21 11:15:51 2016 Timothée Puentes
##

NAME		=	visu

NAME_CLIENT	=	client_visu

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra -I../inc -g3

LIB		=	-L/home/${USER}/.froot/lib	\
			-llapin -lsfml-audio 		\
			-lsfml-graphics -lsfml-window	\
			-lsfml-system -lstdc++ -ldl -lm


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
			../src/parser.c

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
			src/client/display_client.c	\
			src/client/client.c		\
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
			../src/parser.c

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS_SERV) $(OBJS_CLIENT)
	$(CC) -o $(NAME) $(OBJS_SERV)
	$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIB)

clean:
	$(RM) $(OBJS_SERV) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(NAME) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
