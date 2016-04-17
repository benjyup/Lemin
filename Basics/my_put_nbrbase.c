/*
** my_put_nbrbase.c for put_nbr_base in /home/mesqui_v/rendu/Printf/Depot/PSU_2015_my_printf/lib/my
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Nov 12 14:58:55 2015 vincent mesquita
** Last update Mon Nov 30 12:39:03 2015 vincent mesquita
*/

#include "my_basics.h"

void		my_put_nbrbase(unsigned long nb, char *base)
{
  unsigned long	div;
  unsigned long	n;

  div = 1;
  n = my_strlen(base);
  while ((nb / div) >= n)
    div = div * n;
  while (div > 0)
    {
      my_putchar(base[nb / div % n]);
      div = div / n;
    }
}
