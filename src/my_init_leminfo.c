/*
** my_init_leminfo.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 20:35:37 2016 vincent mesquita
** Last update Sun Apr 17 20:39:42 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"

int		my_init_leminfo(t_leminfo *leminfo)
{
  if (!leminfo)
    return (0);
  LINE = 1;
  leminfo->ants_nbr = 0;
  leminfo->pipe = 0;
  leminfo->start = NULL;
  leminfo->end = NULL;
  return (1);
}
