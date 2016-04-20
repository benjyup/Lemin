/*
** my_way.c for  in /home/vincen_s/CPE_2015_Lemin
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Wed Apr 20 12:48:27 2016 Vincent Florian
** Last update Wed Apr 20 17:01:56 2016 Vincent Florian
*/

#include <stdlib.h>
#include "my_basics.h"
#include "parser.h"

static int		my_poids(t_leminfo *data)
{
  t_room_list	*courrant;
  int		i;
  int		j;

  j = -1;
  courrant = data->rl_root->next;
  i = 0;
  while (courrant != data->rl_root && i <= 0)
    {
      if (courrant->PARC == 0)
	i = courrant->POIDS;
      courrant = courrant->next;
    }
  courrant = data->rl_root->next;
  while (courrant != data->rl_root)
    {
      if (courrant->PARC == 0 &&
	  courrant->POIDS > 0 && i >= courrant->POIDS)
	{
	  j = 0;
	  i = courrant->POIDS;
	  data->father = courrant;
	}
      courrant = courrant->next;
    }
  return (j);
}

static void		my_son(t_leminfo *data)
{
  t_link_list	*courrant;
  t_room_list	*current;

  if ((data->father)->ri->links == NULL)
    return ;
  courrant = (data->father)->ri->links->next;
  (data->father)->ri->parcours = 1;
  while (courrant != (data->father)->LINKS)
    {
      current = data->rl_root->next;
      while (current != data->rl_root &&
	     my_strcomp(current->NAME, courrant->link->NAME) != 1)
	current = current->next;
      if ((current->PARC == 0) && (((data->father)->POIDS
				    + 1 < current->POIDS) ||
				   (current->POIDS == -1)))
	{
	  current->POIDS = (data->father)->POIDS + 1;
	  (current->ri->antecedent) = data->father;
	}
      courrant = courrant->next;
    }
}

t_room_list	*my_list_path(t_leminfo *data)
{
  t_room_list	*courrant;
  t_room_list	*my_way;

  courrant = data->father;
  if (!(my_way = create_rl()))
    return (NULL);
  while (courrant->ri->antecedent != NULL)
    {
      my_add_to_begin_room_list(my_way, courrant->ri);
      courrant = courrant->ri->antecedent;
    }
  my_add_to_begin_room_list(my_way, courrant->ri);
  courrant = my_way->next;
  while (courrant != my_way)
    {
      if (courrant->ri->antecedent != NULL)
	printf("1name : %s, antecedent : %s \n", courrant->NAME, (courrant->ri->antecedent)->NAME);
      else
	printf("1name : %s, antecedent : NULL \n", courrant->NAME);
      courrant = courrant->next;
    }
  return (my_way);
}

/* int		my_antman(t_room_list *my_way, t_liminfo *data) */
/* { */
/*   t_room_list	*current; */

/*   i = 1; */
/*   while (data->father->ant_num != data->ants_nbr - 1) */
/*     { */
/*       current = data->father; */
/*       i++; */
/*     } */
/* } */

t_room_list	*my_path(t_leminfo *data)
{
  t_room_list	*courrant;

  /* if ((data->father = malloc(sizeof(t_room_list **))) == NULL) */
  /*   return (NULL); */
  courrant = data->rl_root->next;
  while (courrant != data->rl_root && my_strcomp(courrant->ri->name, data->start) != 1)
    courrant = courrant->next;
  data->father = courrant;
  (data->father)->ri->poids = 0;
  (data->father)->ri->parcours = 1;
  while (my_strcomp((data->father)->NAME, data->end) != 1)
    {
      my_son(data);
      if ((my_poids(data)) == -1)
	return (NULL);
    }
  courrant = data->rl_root->next;
  while (courrant != data->rl_root)
    {
      if (courrant->ri->antecedent != NULL)
	printf("name : %s , antecedent : %s \n", courrant->NAME, (courrant->ri->antecedent)->NAME);
      else
	printf("name : %s, antecedent : START \n", courrant->NAME);
      courrant = courrant->next;
    }
  return (my_list_path(data));
}
