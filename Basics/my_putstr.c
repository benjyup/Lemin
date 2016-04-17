/*
** my_putstr.c for my_putstr in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Nov 30 12:25:03 2015 vincent mesquita
** Last update Sun Apr 17 01:31:17 2016 vincent mesquita
*/

#include <string.h>
#include <unistd.h>
#include "my_basics.h"

int		my_putstr(char *str)
{
  int		length;

  if (str == NULL)
    return (-1);
  length = my_strlen(str);
  write(1, str, length);
  return (length);
}
