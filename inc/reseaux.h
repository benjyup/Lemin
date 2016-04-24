/*
** reseaux.h for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/test
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Apr 20 12:41:48 2016 Timothée Puentes
** Last update Sun Apr 24 23:02:01 2016 Vincent Florian
*/

#ifndef RESEAUX_H_
# define RESEAUX_H_

# include "lemin.h"

# define	PORT 5000
# define	TOTAL_ROOM data->leminfo->total_link
# define	TOTAL_ANT (unsigned int)data->leminfo->ants_nbr
# define	CLIENT data->client
# define	ANTS data->ant
# define	END_NAME data->leminfo->end
# define	START_NAME data->leminfo->start
# define	__IS ((my_strcomp(END_NAME,				\
				  cur->ri->name)) ? ("2") : ("0"))
# define	IS_START ((my_strcomp(START_NAME,			\
				      cur->ri->name)) ? ("1") : (__IS))
# define	PRINT_START ((data->start == 1) ? ("Start") : ("End"))
# define	O_EXIT 1
# define	O_INC 1 << 1
# define	O_OUT 1 << 2
# define	O_NTURN 1 << 3
# define	O_START 1 << 4
# define	O_END 1 << 5

# define	WRITE_ERR "Write failed\n"
# define	READ_ERR "Read failed\n"
# define	SYNTAX_ERR "Syntaxe error\n"

typedef struct	s_order
{
  char		type;
  int		data;
}		t_order;

typedef union	u_swap_port
{
  short		sh;
  char		nb[2];
}		t_swap_port;

typedef struct	s_resaux
{
  int		sockfd;
  int		*client;
  char		**ant;
  t_leminfo	*leminfo;
}		t_reseaux;

short		swap(short port);
void		my_memset(char *pnt, int size, char value);
char		*my_memcpy(char *dest, char *src, int size);
int		send_order(int sockfd, char order, int data);
int		broadcast_order(t_reseaux *data, char order, int arg);
int		treat_data(t_reseaux *data);
int		wait_for_next(t_reseaux *data);

#endif /* RESEAUX_H_ */
