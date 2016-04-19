/*
** find_way.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Apr 18 11:50:38 2016 Timothée Puentes
** Last update Tue Apr 19 14:44:01 2016 Timothée Puentes
*/

#include <stdlib.h>
#include <unistd.h>
#include "lemin.h"
#include "my_basics.h"

void		free_path(t_path *path)
{
  t_path	*cur;
  t_path	*tmp;

  cur = path;
  while (cur != NULL)
    {
      tmp = cur;
      cur = cur->next;
      free(tmp->name);
      free(tmp);
    }
  path = NULL;
}

void		add_path_at_end(t_path *root, t_path *new)
{
  t_path	*cur;

  cur = root;
  while (cur->next != NULL)
    cur = cur->next;
  cur->next = new;
  new->next = NULL;
}

t_path		*create_a_path(char *str)
{
  t_path	*tmp;

  if ((tmp = malloc(sizeof(t_path))) == NULL ||
      (tmp->name = my_strcpy(str)) == NULL)
    return (my_puterror_pnt(MALLOC_ERR));
  tmp->next = NULL;
  return (tmp);
}

t_path		*cpy_new_path(t_path *old,
			      char *new_name)
{
  t_path	*cur;
  t_path	*new_root;
  t_path	*tmp;

  cur = old;
  if ((new_root = create_a_path(cur->name)) == NULL)
    return (NULL);
  cur = cur->next;
  while (cur != NULL)
    {
      if ((tmp = create_a_path(cur->name)) == NULL)
	return (NULL);
      add_path_at_end(new_root, tmp);
      cur = cur->next;
    }
  if ((tmp = create_a_path(new_name)) == NULL)
    return (NULL);
  add_path_at_end(new_root, tmp);
  return (new_root);
}

void		free_way(t_path **path)
{
  int		c;
  t_path	*cur;
  t_path	*tmp;

  c = 0;
  while (path[c] != NULL)
    {
      cur = path[c];
      while (cur != NULL)
	{
	  tmp = cur;
	  cur = cur->next;
	  free(tmp->name);
	  free(tmp);
	}
      c += 1;
    }
  free(path);
}

static t_path	**init_way(t_room_list *root,
			   t_leminfo *data)
{
  t_room_list	*tmp;
  t_path	**path;
  unsigned int	c;

  if ((path = malloc(sizeof(t_path *) * (data->total_link + 1))) == NULL)
    return (NULL);
  tmp = root->next;
  c = 0;
  while (c < data->total_link)
    {
      if ((path[c] = malloc(sizeof(t_path))) == NULL ||
	  (path[c]->name = my_strcpy(tmp->ri->name)) == NULL)
	return (NULL);
      path[c]->next = NULL;
      tmp = tmp->next;
      c += 1;
    }
  path[c] = NULL;
  return (path);
}

static t_path	*init_path(t_leminfo *data)
{
  t_path	*path;

  if ((path = malloc(sizeof(t_path))) == NULL ||
      (path->name = my_strcpy(data->start)) == NULL)
    return (NULL);
  path->next = NULL;
  return (path);
}

t_path		**find_path(t_room_list *root,
			    t_leminfo *data)
{
  t_path	**list_path;
  t_path	*path;

  if ((list_path = init_way(root, data)) == NULL ||
      (path = init_path(data)) == NULL ||
      recur_path(list_path, path, root, data) == ERR)
    return (NULL);
  return (list_path);
}
