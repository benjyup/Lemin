/*
** recur_path.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Apr 18 12:24:38 2016 Timothée Puentes
** Last update Tue Apr 19 16:11:17 2016 Timothée Puentes
*/

#include <stdlib.h>
#include "lemin.h"
#include "my_basics.h"

static t_room_list	*get_rank(t_room_list *graph_root,
				  int *c,
				  char *str)
{
  t_room_list		*tmp;

  tmp = graph_root->next;
  while (my_strcomp(tmp->ri->name, str) != 1)
    {
      tmp = tmp->next;
      *c += 1;
    }
  return (tmp);
}

static int		get_list_size(t_path *path)
{
  int			c;
  t_path		*cur;

  c = 0;
  cur = path;
  while (cur != NULL)
    {
      cur = cur->next;
      c += 1;
    }
  return (c);
}

static int		stock(t_path **list_path,
			      int rank,
			      t_path *act_path)
{
  t_path	*cur;
  t_path	*tmp;

  free_path(list_path[rank]->next);
  list_path[rank]->next = NULL;
  cur = act_path;
  while (cur != NULL)
    {
      if ((tmp = create_a_path(cur->name)) == NULL)
	return (my_puterror(MALLOC_ERR));
      add_path_at_end(list_path[rank], tmp);
      cur = cur->next;
    }
  return (0);
}

int			recur_path(t_path **list_path,
				   t_path *act_path,
				   t_room_list *graph_root,
				   t_leminfo *data)
{
  int			c;
  t_path		*tmp;
  t_room_list		*act_room;
  t_path		*new_path;
  t_link_list		*root_link;
  t_link_list		*cur_link;

  tmp = act_path;
  while (tmp->next != NULL)
    tmp = tmp->next;
  c = 0;
  act_room = get_rank(graph_root, &c, tmp->name);
  if (list_path[c]->next == NULL ||
      get_list_size(act_path) < get_list_size(list_path[c]->next))
    stock(list_path, c, act_path);
  else
    return (SUCCESS);
  printf("\nFrom %s\n", list_path[c]->name);
  c = 0;
  if ((root_link = act_room->ri->links) == NULL)
    return (SUCCESS);
  cur_link = root_link->next;
  while (cur_link != root_link)
    {
	  printf("got %s\n", cur_link->link->ri->name);
 	  if ((new_path = cpy_new_path(act_path, cur_link->link->ri->name)) == NULL ||
	      recur_path(list_path, new_path, graph_root, data) == ERR)
	    return (ERR);
	  free_path(new_path);
      cur_link = cur_link->next;
      c += 1;
    }
  return (SUCCESS);
}
