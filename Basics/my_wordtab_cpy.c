/*
** my_wordtab_cpy.c for my_wordtab_cpy.c in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Jan 11 15:59:29 2016 vincent mesquita
** Last update Sun Apr 17 01:29:11 2016 vincent mesquita
*/

#include <stdlib.h>
#include "my_basics.h"

char		**my_wordtab_cpy(char **wordtab)
{
  char		**cpy;
  unsigned int	i;

  if (wordtab == NULL || wordtab[0] == NULL)
    return (NULL);
  if ((cpy = malloc((my_wordtab_len(wordtab) + 1)
		    * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (wordtab[i] != NULL)
    {
      if((cpy[i] = my_strcpy(wordtab[i])) == NULL)
	return (NULL);
      i = i + 1;
    }
  cpy[i] = NULL;
  return (cpy);
}
