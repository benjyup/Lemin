/*
** my_ways_list.c for my_ways_list.c in /home/vincen_s/CPE_2015_Lemin
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Fri Apr 22 11:41:04 2016 Vincent Florian
** Last update Sun Apr 24 16:56:05 2016 Vincent Florian
*/

#include <stdlib.h>
#include "my_basics.h"
#include "parser.h"

t_ways		*create_ways(void)
{
  t_ways	*rl_root;

  if (!(rl_root = malloc(sizeof(*rl_root))))
    return (NULL);
  rl_root->way = NULL;
  rl_root->next = rl_root;
  rl_root->prev = rl_root;
  return (rl_root);
}

void		my_delete_list(t_ways *curr)
{
  t_ways	*next;
  t_ways	*prev;

  next = curr->next;
  prev = curr->prev;
  prev->next = next;
  next->prev = prev;
}

int		my_add_to_end_ways_list(t_ways *root,
					t_room_list *ri)
{
  t_ways	*new_rl;
  t_ways	*current;

  if (!root || !ri)
    return (-1);
  if (!(new_rl = malloc(sizeof(*new_rl))))
    return (my_puterror(MALLOC_ERR));
  current = root->prev;
  new_rl->way = ri;
  new_rl->next = root;
  new_rl->prev = current;
  current->next = new_rl;
  root->prev = new_rl;
  return (0);
}
