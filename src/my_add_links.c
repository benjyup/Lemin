/*
** my_add_links.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Tue Apr 19 11:11:20 2016 vincent mesquita
** Last update Tue Apr 19 16:34:40 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

static int	my_add_to_list(t_link_list *root,
			       t_room_list *link_to)
{
  t_link_list		*new_ll;
  t_link_list		*current;

  if (!root || !link_to)
    return (-1);
  current = root->prev;
  if (!(new_ll = malloc(sizeof(*new_ll))))
    return (my_puterror(MALLOC_ERR));
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

void		show(t_link_list *root)
{
  t_link_list	*current;

  current = root->next;
  while (current != root)
    {
      my_putstr(current->link->NAME);
      my_putchar(10);
      current = current->next;
    }
}

int		add_the_link(t_leminfo *leminfo,
			     char **wordtab,
			     t_room_list *current)
{
  t_room_list	*link_to;

  /*check le retour*/
  if (current->LINKS == NULL
      && !(current->LINKS = create_ll()))
    return (my_puterror(MALLOC_ERR));
  link_to = ROOT->next;
  while (link_to != ROOT && !my_strcomp(link_to->NAME, wordtab[1]))
    link_to = link_to->next;
  if (link_to == ROOT)
    return (my_puterror2("Error: Bad link\n", LINE));
  if (my_add_to_list(current->LINKS, link_to) == -1)
    return (-1);
  return (0);
}

int		my_add_links(t_leminfo *leminfo,
			     char **wordtab)
{
  t_room_list	*current;

  if (!leminfo || !wordtab)
    return (-1);
  current = ROOT->next;
  while (current != ROOT)
    {
      if (my_strcomp(current->NAME, wordtab[0]))
	{
	  if (add_the_link(leminfo, wordtab, current) == -1)
	    return (-1);
	  return (0);
	}
      current = current->next;
    }
  return (my_puterror2("Error: Bad link\n", LINE));
}
