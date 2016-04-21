/*
** reseaux.h for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/test
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Apr 20 12:41:48 2016 Timothée Puentes
** Last update Thu Apr 21 10:31:33 2016 Timothée Puentes
*/

#ifndef RESEAUX_H_
# define RESEAUX_H_

# include "lemin.h"

# define	PORT 1042
# define	TOTAL_ROOM data->leminfo->total_link
# define	TOTAL_ANT (unsigned int)data->leminfo->ants_nbr
# define	CLIENT data->client
# define	ANTS data->ant
# define	START_NAME data->leminfo->start

# define	O_EXIT 0
# define	O_INC 1
# define	O_OUT 2
# define	O_NTURN 3

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

#endif /* RESEAUX_H_ */
