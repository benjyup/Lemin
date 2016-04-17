/*
** my_strcpy.c for my_strcpy in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Jan 11 13:18:29 2016 vincent mesquita
** Last update Mon Jan 11 13:22:13 2016 vincent mesquita
*/

#include <stdlib.h>
#include "my_basics.h"

char		*my_strcpy(char *str)
{
  unsigned int	i;
  char		*cpy;

  if (str == NULL)
    return (NULL);
  if ((cpy = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      cpy[i] = str[i];
      i = i + 1;
    }
  cpy[i] = 0;
  return (cpy);
}
