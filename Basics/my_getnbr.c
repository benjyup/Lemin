/*
** my_getnbr.c for my_get_nbr in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Nov 30 12:29:52 2015 vincent mesquita
** Last update Mon Apr 11 13:16:39 2016 vincent mesquita
*/

#include <stdlib.h>

int		my_getnbr(char *str)
{
  int		i;
  int		nbr;
  int		neg;

  i = 0;
  nbr = 0;
  neg = 0;
  if (str == NULL)
    return (-1);
  while ((str[i] < '0' || str[i] > '9') && str[i] != 0)
    {
      if (str[i] == '-')
	neg = neg + 1;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10 + str[i] - 48;
      i = i + 1;
    }
  if (neg % 2 == 1)
    nbr = nbr * (-1);
  return (nbr);
}

long		my_getnbr_long(char *str)
{
  long		i;
  long		nbr;
  long		neg;

  i = 0;
  nbr = 0;
  neg = 0;
  if (str == NULL)
    return (-1);
  while ((str[i] < '0' || str[i] > '9') && str[i] != 0)
    {
      if (str[i] == '-')
	neg = neg + 1;
      i = i + 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10 + str[i] - 48;
      i = i + 1;
    }
  if (neg % 2 == 1)
    nbr = nbr * (-1);
  return (nbr);
}
