/*
** my_show_wordtab.c for my_show_wodtab in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Jan  8 12:26:55 2016 vincent mesquita
** Last update Sun Apr 17 01:33:31 2016 vincent mesquita
*/

#include <string.h>
#include "my_basics.h"

int		my_show_wordtab(char **wordtab)
{
  unsigned int	i;

  i = 0;
  if (wordtab == NULL)
    return (-1);
  while (wordtab[i] != NULL)
    {
      my_putstr(wordtab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
