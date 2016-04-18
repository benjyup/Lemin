/*
** my_fill_room_list.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Apr 18 11:04:15 2016 vincent mesquita
** Last update Mon Apr 18 11:43:24 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

static void		my_show_room_list(t_room_list *root)
{
  t_room_list		*current;

  current = root->next;
  while (current != root)
    {
      my_putstr(current->ri->name);
      my_put_nbr(current->ri->pos.x);
      my_put_nbr(current->ri->pos.y);
      current = current->next;
    }
}

int			my_fill_room_list(t_leminfo *leminfo,
					  char **wordtab)
{
  t_room_info		*ri;

  if (LINE == 1)
    return (0);
  if (!(ri = malloc(sizeof(*ri))))
    return (my_puterror(MALLOC_ERR));
  if (my_wordtab_len(wordtab) != 3)
    return (my_puterror2("Error: Bad format\n", LINE));
  if (!(ri->name = my_strcpy(wordtab[0])))
    return (my_puterror(MALLOC_ERR));
  if (my_nan(wordtab[0]) || my_nan(wordtab[1]))
    return (my_puterror2("Error: Bad format\n", LINE));
  ri->pos.x = my_getnbr(wordtab[1]);
  ri->pos.y = my_getnbr(wordtab[2]);
  if (my_add_to_end_room_list(leminfo->rl_root, ri) == -1)
    return (-1);
  my_show_room_list(leminfo->rl_root);
  return (0);
}
