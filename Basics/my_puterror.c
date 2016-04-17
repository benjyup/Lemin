/*
** my_puterror.c for my_puterror in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Jan  8 15:30:26 2016 vincent mesquita
** Last update Mon Apr 11 12:33:09 2016 vincent mesquita
*/

#include <string.h>
#include <unistd.h>
#include "my_basics.h"

int		my_puterror(char *str)
{
  int		length;

  if (str == NULL)
    return (-1);
  length = my_strlen(str);
  write(2, str, length);
  return (-1);
}
