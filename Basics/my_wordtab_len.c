/*
** my_wordtab_len.c for my_wordtab_len in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Jan 11 13:43:52 2016 vincent mesquita
** Last update Sun Apr 17 01:29:00 2016 vincent mesquita
*/

#include <stdlib.h>

unsigned int		my_wordtab_len(char **wordtab)
{
  unsigned int		length;

  length = 0;
  if (wordtab == NULL || wordtab[0] == NULL)
    return (0);
  while (wordtab[length] != NULL)
    length = length + 1;
  return (length);
}
