/*
** free_leminfo.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 03:25:48 2016 vincent mesquita
** Last update Wed Apr 20 16:01:10 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"

static int	my_free_room_list(t_room_list *root)
{
  t_room_list	*current;

  current = root->next;;
}

void		free_leminfo(t_leminfo *leminfo)
{
  if (leminfo->start != NULL)
    free(leminfo->start);
  if (leminfo->end != NULL)
    free(leminfo->end);
}
