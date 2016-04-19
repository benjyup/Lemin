/*
** my_puterror.c for my_puterror in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Jan  8 15:30:26 2016 vincent mesquita
** Last update Tue Apr 19 12:52:54 2016 Timothée Puentes
*/

#include <string.h>
#include <unistd.h>
#include "my_basics.h"

void		my_putchar_error(char c)
{
  if (write(2, &c, 1) == -1)
    return ;
}

int		my_put_nbr_error(int nbr)
{
  if (nbr < 0)
    {
      nbr = nbr * (-1);
      my_putchar('-');
    }
  if (nbr >= 10)
    my_put_nbr_error(nbr / 10);
  my_putchar_error(nbr % 10 + '0');
  return (-1);
}

int		my_puterror(char *str)
{
  int		length;

  if (str == NULL)
    return (-1);
  length = my_strlen(str);
  write(2, str, length);
  return (-1);
}

void		*my_puterror_pnt(char *str)
{
  int		length;

  if (str == NULL)
    return (NULL);
  length = my_strlen(str);
  write(2, str, length);
  return (NULL);
}

int		my_puterror2(char *str, int line)
{
  my_puterror("Error: line ");
  my_put_nbr_error(line);
  my_puterror(": ");
  my_puterror(str);
  return (-1);
}
