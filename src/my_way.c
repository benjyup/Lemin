/*
** my_way.c for  in /home/vincen_s/CPE_2015_Lemin
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Wed Apr 20 12:48:27 2016 Vincent Florian
** Last update Wed Apr 20 12:51:03 2016 Vincent Florian
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
	  (*data->father) = courrant;
	}
      courrant = courrant->next;
    }
  return (j);
}

static void		my_son(t_leminfo *data)
{
  t_link_list	*courrant;
  t_room_list	*current;

  if ((*data->father)->ri->links == NULL)
    return ;
  courrant = (*data->father)->ri->links->next;
  (*data->father)->ri->parcours = 1;
  while (courrant != (*data->father)->LINKS)
    {
      current = data->rl_root->next;
      while (current != data->rl_root &&
	     my_strcomp(current->NAME, courrant->link->NAME) != 1)
	current = current->next;
      if ((current->PARC == 0) && (((*data->father)->POIDS
				    + 1 < current->POIDS) ||
				   (current->POIDS == -1)))
	{
	  current->POIDS = (*data->father)->POIDS + 1;
	  current->ri->antecedent = (*data->father)->NAME;
	}
      courrant = courrant->next;
    }
}

void		my_path(t_leminfo *data)
{
  t_room_list	*courrant;
  t_room_list	**father;

  if ((father = malloc(sizeof(**father))) == NULL)
    return ;
  courrant = data->rl_root->next;
  while (courrant != data->rl_root && my_strcomp(courrant->ri->name, data->start) != 1)
    courrant = courrant->next;
  *father = courrant;
  data->father = father;
  (*data->father)->ri->poids = 0;
  (*data->father)->ri->parcours = 1;
  while (my_strcomp((*data->father)->NAME, data->end) != 1)
    {
      my_son(data);
      if ((my_poids(data)) == -1)
	return ;
    }
  courrant = data->rl_root->next;
  while (courrant != data->rl_root)
    {
      printf("name : %s , antecedent : %s \n", courrant->NAME, courrant->ri->antecedent);
      courrant = courrant->next;
    }
}
