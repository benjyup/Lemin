/*
** reseaux.h for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/test
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Apr 20 12:41:48 2016 Timothée Puentes
** Last update Wed Apr 20 12:42:48 2016 Timothée Puentes
*/

#ifndef RESEAUX_H_
# define RESEAUX_H_

typedef union	u_swap_port
{
  short		sh;
  char		nb[2];
}		t_swap_port;

short			swap(short port);
void			my_memset(char *pnt, int size, char value);
char			*my_memcpy(char *dest, char *src, int size);

#endif /* RESEAUX_H_ */
