/*
** is_a_comment.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed Apr 20 14:51:46 2016 vincent mesquita
** Last update Wed Apr 20 15:10:06 2016 vincent mesquita
*/

#include "my_basics.h"

static int	hash_count(char *str)
{
  unsigned int	i;
  unsigned int count;

  i = 0;
  count = 0;
  while (str[i])
    {
      count += ((str[i] == '#') ? (1) : (0));
      i += 1;
    }
  return (count);
}

int		is_a_comment(char *str)
{
  unsigned int	i;
  int		count;

  i = 0;
  if (!str[i])
    return (0);
  return (((hash_count(str) == 1) ? (1) : (0)));
}
