/*
** my_free_wordtab.c for my_free_wordtab in /home/mesqui_v/rendu/Minishell1/Bootstrap/PSU_2015_my_exec
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Jan  8 12:12:32 2016 vincent mesquita
** Last update Sat Jan 23 12:14:55 2016 vincent mesquita
*/

#include <stdlib.h>
#include "my_basics.h"

int		my_free_wordtab(char **wordtab)
{
  unsigned int	i;

  if (wordtab == NULL)
    return (-1);
  i = 0;
  while (wordtab[i] != NULL)
    {
      if (wordtab[i] != NULL)
	free(wordtab[i]);
      i += 1;
    }
  if (wordtab != NULL)
    free(wordtab);
  return (0);
}
