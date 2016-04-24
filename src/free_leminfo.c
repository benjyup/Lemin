/*
** free_leminfo.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 03:25:48 2016 vincent mesquita
** Last update Sun Apr 24 16:23:59 2016 Peixoto Benjamin
*/

#include <stdlib.h>
#include "parser.h"

static void	my_free_link_list(t_link_list *root)
{
  t_link_list	*current;
  t_link_list	*tmp;

  if (!root)
    return ;
  current = root->next;
  while (current != root)
    {
      tmp = current;
      current = current->next;
      free(tmp);
    }
  free(root);
}

static void	my_free_room_info(t_room_info *ri)
{
  if (!ri)
    return ;
  if (NAME)
    free(NAME);
  if (LINKS)
    my_free_link_list(LINKS);
  free(ri);
}

void		my_free_room_list(t_room_list *root)
{
  t_room_list	*current;
  t_room_list	*tmp;

  if (!root)
    return ;
  current = root->next;
  while (current != root)
    {
      my_free_room_info(current->ri);
      tmp = current;
      current = current->next;
      free(tmp);
    }
  free(root);
}

void		free_leminfo(t_leminfo *leminfo)
{
  if (leminfo->start != NULL)
    free(leminfo->start);
  if (leminfo->end != NULL)
    free(leminfo->end);
  my_free_room_list(ROOT);
}
