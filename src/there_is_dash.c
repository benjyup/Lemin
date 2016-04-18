/*
** there_is_dash.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 02:34:45 2016 vincent mesquita
** Last update Mon Apr 18 10:41:21 2016 vincent mesquita
*/

#include "parser.h"

int		there_is_dash(char *str,
			      t_leminfo *leminfo)
{
  int		i;

  if (!str)
    return (0);
  i = -1;
  while (str[++i])
    if (str[i] == '-')
      {
	leminfo->pipe = 1;
	return (1);
      }
  return (0);
}
