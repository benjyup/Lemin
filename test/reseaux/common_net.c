/*
** common_net.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/test
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Apr 20 12:40:52 2016 Timothée Puentes
** Last update Wed Apr 20 12:49:55 2016 Timothée Puentes
*/

#include "reseaux.h"

void			my_memset(char *pnt, int size, char value)
{
  int			c;

  c = 0;
  while (c < size)
    pnt[c++] = value;
}

short			swap(short port)
{
  t_swap_port		act;
  char			tmp;

  act.sh = port;
  tmp = act.nb[1];
  act.nb[1] = act.nb[0];
  act.nb[0] = tmp;
  return (act.sh);
}

char			*my_memcpy(char *dest, char *src, int size)
{
  int			c;

  c = -1;
  while (++c < size)
    dest[c] = src[c];
}
