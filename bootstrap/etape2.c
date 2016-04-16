/*
** etape2.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/bootstrap
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Apr 15 19:54:55 2016 vincent mesquita
** Last update Fri Apr 15 20:10:21 2016 vincent mesquita
*/

#include "my.h"

int		my_add_to_end_ways(t_ways *root,
				   t_maillon *maillon)
{
  t_ways	*current;
  t_ways	*new_way;

  if (!root || !maillon)
    return (-1);
  current = root->prev;
  if (!(new_way = malloc(sizeof(*new_way))))
    return (-1);
  new_way->maillon = maillon;
  new_way->next = root;
  new_way->prev = current;
  current->next = new_way;
  root->prev = new_way;
}

void		link_maillon(t_maillon *maillon1,
			     t_maillon *maillon2)
{
  if (!maillon1 || !maillon2)
    return ;
  if (my_add_to_end_ways(maillon1->ways_root,
			 maillon2) == -1)
    return ;
}
