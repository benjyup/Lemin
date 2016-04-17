/*
** my_strlen.c for my_strlen in /home/mesqui_v/rendu/WorkshopLib
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Oct 15 10:57:28 2015 vincent mesquita
** Last update Fri Jan 29 22:12:44 2016 vincent mesquita
*/

#include <string.h>

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
