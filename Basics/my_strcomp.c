/*
** my_strcomp.c for my_strcomp.c in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Jan  8 15:24:19 2016 vincent mesquita
** Last update Wed Mar 16 15:30:19 2016 vincent mesquita
*/

#include <string.h>
#include "my_basics.h"

int		my_strcomp(char *str1, char *str2)
{
  unsigned int	i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  if (my_strlen(str1) != my_strlen(str2))
    return (0);
  i = 0;
  while (str1[i])
    {
      if (str1[i] != str2[i])
	return (0);
      i = i + 1;
    }
  return (1);
}
