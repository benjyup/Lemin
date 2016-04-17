/*
** my_put_nbrlong.c for my_put_nbrlong in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Nov 30 12:37:22 2015 vincent mesquita
** Last update Mon Nov 30 12:40:08 2015 vincent mesquita
*/

#include "my_basics.h"

void		my_put_nbrlong(long long nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
