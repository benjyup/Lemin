/*
** my_put_nbr.c for my_put_nbr in /home/mesqui_v/rendu/WorkshopLib
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Oct 15 10:21:43 2015 vincent mesquita
** Last update Fri Mar 18 15:15:59 2016 vincent mesquita
*/

#include "my_basics.h"

void	my_put_nbr(int nb)
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
