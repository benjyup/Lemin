/*
** my_delete_to_wordtab.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar/asm
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Mar 24 17:07:08 2016 vincent mesquita
** Last update Sun Apr 17 01:32:11 2016 vincent mesquita
*/

#include <stdlib.h>
#include "my_basics.h"

char		**my_delete_to_wordtab(char **wordtab, int idx)
{
  int		i;
  int		y;
  int		length;
  char		**cpy;

  if (wordtab == NULL || (length = my_wordtab_len(wordtab)) == 0)
    return (NULL);
  if ((cpy = malloc(length * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  y = 0;
  while (y < length)
    {
      if (y == idx)
	y += 1;
      if (wordtab[y] == NULL
	  || (cpy[i] = my_strcpy(wordtab[y])) == NULL)
	return (NULL);
      if (wordtab[y] != NULL)
	y += 1;
      i += 1;
    }
  cpy[i] = NULL;
  return (cpy);
}
