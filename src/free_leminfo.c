/*
** free_leminfo.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 03:25:48 2016 vincent mesquita
** Last update Mon Apr 18 12:42:32 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"

void		free_leminfo(t_leminfo *leminfo)
{
  if (leminfo->start != NULL)
    free(leminfo->start);
  if (leminfo->end != NULL)
    free(leminfo->end);
}
