/*
** my_add_links.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Apr 19 11:11:20 2016 vincent mesquita
** Last update Sun Apr 24 16:27:37 2016 Peixoto Benjamin
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

static int		name_already_used(char *name,
					  t_link_list *root)
{
  t_link_list		*current;

  if (!name || !root)
    return (1);
  current = root->next;
  while (current != root)
    {
      if (my_strcomp(name, current->link->NAME))
	return (1);
      current = current->next;
    }
  return (0);
}

static int		my_add_to_list(t_link_list *root,
			       t_room_list *link_to)
{
  t_link_list		*new_ll;
  t_link_list		*current;

  if (!root || !link_to)
    return (-1);
  if (name_already_used(link_to->NAME, root))
    return (0);
  current = root->prev;
  if (!(new_ll = malloc(sizeof(*new_ll))))
    return (-2);
  new_ll->link = link_to;
  new_ll->next = root;
  new_ll->prev = current;
  current->next = new_ll;
  root->prev = new_ll;
  return (0);
}

static t_link_list	*create_ll(void)
{
  t_link_list		*root;

  if (!(root = malloc(sizeof(*root))))
    return (NULL);
  root->link = NULL;
  root->next = root;
  root->prev = root;
  return (root);
}

int			add_the_link(t_leminfo *leminfo,
				     char **wordtab,
				     t_room_list *current)
{
  t_room_list		*link_to;

  if (current->LINKS == NULL
      && !(current->LINKS = create_ll()))
    return (-2);
  link_to = ROOT->next;
  while (link_to != ROOT && !my_strcomp(link_to->NAME, wordtab[1]))
    link_to = link_to->next;
  if (link_to == ROOT)
    return (my_puterror2("Error: Bad link\n", LINE));
  if (my_add_to_list(current->LINKS, link_to) < 0)
    return (-2);
  return (0);
}

int			my_add_links(t_leminfo *leminfo,
				     char **wordtab)
{
  t_room_list		*current;

  if (!leminfo || !wordtab)
    return (-1);
  current = ROOT->next;
  while (current != ROOT)
    {
      if (my_strcomp(current->NAME, wordtab[0]))
	{
	  if (add_the_link(leminfo, wordtab, current) < 0)
	    return (-2);
	  return (0);
	}
      current = current->next;
    }
  return (my_puterror2("Error: Bad link\n", LINE));
}
