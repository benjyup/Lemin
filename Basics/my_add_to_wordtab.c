/*
** my_add_to_wordtab.c for my_add_to_wordtab in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Thu Jan 21 10:59:00 2016 vincent mesquita
** Last update Thu Jan 21 11:44:27 2016 vincent mesquita
*/

#include <stdlib.h>
#include "my_basics.h"

char		**my_add_to_wordtab(char **wordtab, char *str)
{
  char		**cpy;
  unsigned int	i;
  unsigned int	length;

  if (wordtab == NULL || wordtab[0] == NULL || str == NULL)
    return (NULL);
  length = my_wordtab_len(wordtab);
  if ((cpy = malloc((length + 2) *sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (wordtab[i] != NULL)
    {
      if ((cpy[i] = my_strcpy(wordtab[i])) == NULL)
	return (NULL);
      i = i + 1;
    }
  if ((cpy[i++] = my_strcpy(str)) == NULL)
    return (NULL);
  cpy[i] = NULL;
  my_free_wordtab(wordtab);
  return (cpy);
}
