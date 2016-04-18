/*
** my_init_leminfo.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 20:35:37 2016 vincent mesquita
** Last update Mon Apr 18 12:24:35 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

int			my_add_to_end_room_list(t_room_list *root,
						t_room_info *ri)
{
  t_room_list		*new_rl;
  t_room_list		*current;

  if (!root)
    return (-1);
  current = root->prev;
  if (!(new_rl = malloc(sizeof(*new_rl))))
    return (my_puterror(MALLOC_ERR));
  new_rl->ri = ri;
  new_rl->next = root;
  new_rl->prev = current;
  current->next = new_rl;
  root->prev = new_rl;
  return (0);
}

static t_room_list	*create_rl(void)
{
  t_room_list		*rl_root;

  if (!(rl_root = malloc(sizeof(*rl_root))))
    return (NULL);
  rl_root->ri = NULL;
  rl_root->next = rl_root;
  rl_root->prev = rl_root;
  return (rl_root);
}

int			my_init_leminfo(t_leminfo *leminfo)
{
  if (!leminfo
      || !(leminfo->rl_root = create_rl()))
    return (0);
  LINE = 1;
  leminfo->total_link = 0;
  leminfo->ants_nbr = 0;
  leminfo->pipe = 0;
  leminfo->start_end = 0;
  leminfo->start = NULL;
  leminfo->end = NULL;
  return (1);
}
