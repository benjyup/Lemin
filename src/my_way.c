/*
** my_way.c for  in /home/vincen_s/CPE_2015_Lemin
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Wed Apr 20 12:48:27 2016 Vincent Florian
** Last update Sun Apr 24 21:04:34 2016 vincent mesquita
*/

#include <stdlib.h>
#include "my_basics.h"
#include "parser.h"

static int	my_poids(t_leminfo *data, int i)
{
  t_room_list	*courrant;
  int		j;

  j = -1;
  courrant = data->rl_root->next;
  while (courrant && courrant->ri && courrant != data->rl_root && i <= 0)
    {
      if (courrant->PARC == 0)
	i = courrant->POIDS;
      courrant = courrant->next;
    }
  courrant = data->rl_root->next;
  while (courrant && courrant->ri && courrant != data->rl_root)
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

static void	my_son(t_leminfo *data)
{
  t_link_list	*courrant;
  t_room_list	*current;

  if ((data->father)->ri == NULL || data->father->ri->links == NULL)
    return ;
  courrant = (data->father)->ri->links->next;
  (data->father)->ri->parcours = 1;
  while (courrant && courrant->link && courrant != (data->father)->LINKS)
    {
      current = data->rl_root->next;
      while (current && current->ri && current != data->rl_root &&
	     my_strcomp(current->NAME, courrant->link->NAME) != 1)
	current = current->next;
      if (current->ri && (current->PARC == 0) &&
	  (((data->father)->POIDS + 1 < current->POIDS) ||
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
  int		i;

  i = 0;
  courrant = data->father;
  if (!(my_way = create_rl()))
    return (NULL);
  while (courrant->ri->antecedent != NULL)
    {
      my_add_to_begin_room_list(my_way, courrant->ri);
      courrant = courrant->ri->antecedent;
      i++;
    }
  my_add_to_begin_room_list(my_way, courrant->ri);
  my_way->next->ri->lenght = 1;
  return (my_way);
}

void		print_my_move(t_room_list *current, int *flag)
{
  my_putchar('P');
  my_put_nbr(current->ri->ant_num);
  my_putchar('-');
  my_putstr(current->next->ri->name);
  my_putchar(' ');
  *flag = 1;
}

void		move_my_ants(t_leminfo *data, int *i, t_ways *curr, int *flag)
{
  t_room_list	*current;

  current = curr->way->prev;
  current->ri->ant_num = 0;
  while (current->prev != curr->way && current->ri->ant_num == 0)
    current = current->prev;
  while (current && current->ri && current != curr->way)
    {
      if (current->ri->ant_num > 0 &&
	  current->ri->ant_num < data->ants_nbr + 1)
	print_my_move(current, flag);
      current->next->ri->ant_num = current->ri->ant_num;
      current = current->prev;
    }
  current = current->next;
  (*i)++;
  if (*i < data->ants_nbr + 1)
    current->ri->ant_num = *i;
  else if (current->ri != NULL)
    current->ri->ant_num = 0;
}

int		my_antman(t_ways *my_way, t_leminfo *data)
{
  t_ways	*curr;
  int		i;
  int		flag;

  i = 0;
  curr = my_way;
  while (curr->next->way->prev
	 && curr->next->way->prev->ri->ant_num <
	 data->ants_nbr - (data->ants_nbr + 1) % 2)
    {
      flag = 0;
      curr = my_way->next;
      while (curr && curr != my_way)
	{
	  move_my_ants(data, &i, curr, &flag);
	  curr = curr->next;
	}
      if (flag == 1)
	my_putchar('\n');
    }
  if (data->ants_nbr > 1 && data->ants_nbr % 2 == 0)
    print_my_move2(data, my_way);
  return (0);
}

void		my_check_ways(t_ways *ways)
{
  int		lenght;
  int		i;
  t_ways	*curr;
  t_room_list	*current;

  lenght = -1;
  curr = ways->next;
  while (curr && curr->way && curr != ways)
    {
      i = 0;
      current = curr->way;
      while ((current = current->next) != curr->way)
	i++;
      if (lenght == -1 || i < lenght)
	lenght = i;
      curr = curr->next;
    }
  curr = ways->next;
  while (curr && curr->way && curr != ways)
    {
      i = 0;
      current = curr->way;
      while ((current = current->next) != curr->way)
	i++;
      if (i != lenght)
	my_delete_list(curr);
      curr = curr->next;
    }
}

void		reset_data(t_leminfo *data)
{
  t_room_list	*curr;

  curr = data->rl_root->next;
  while (curr && curr->ri && curr != data->rl_root)
    {
      curr->ri->poids =-1;
      curr->ri->ant_num = 0;
      curr->ri->antecedent = NULL;
      curr = curr->next;
    }
}

int		find_my_ways(t_room_list *courrant, t_leminfo *data,
			     t_ways *ways)
{
  t_link_list	*curr;
  t_room_list	*path;

  if (courrant->ri->links == NULL)
    return (-1);
  curr = courrant->ri->links->next;
  while (curr && curr->link && curr != courrant->ri->links)
    {
      data->father = curr->link;
      (data->father)->ri->poids = 0;
      (data->father)->ri->parcours = 1;
      while (my_strcomp((data->father)->NAME, data->end) != 1)
	{
	  my_son(data);
	  if ((my_poids(data, 0)) == -1)
	    break ;
	}
      if (my_strcomp(data->father->NAME, data->end) &&
	  (path = my_list_path(data)) != NULL)
	my_add_to_end_ways_list(ways, path);
      reset_data(data);
      curr = curr->next;
    }
  if (ways->next == ways)
    return (-1);
  return (0);
}

t_ways		*my_path(t_leminfo *data)
{
  t_room_list	*courrant;
  t_ways	*ways;
  t_ways	*current;

  if (data->rl_root->next == NULL)
    return (NULL);
  courrant = data->rl_root->next;
  while (courrant != data->rl_root && courrant->ri &&
	 my_strcomp(courrant->ri->name, data->start) != 1)
    courrant = courrant->next;
  if (courrant == data->rl_root || !courrant->ri || !courrant->ri->links ||
      (ways = create_ways()) == NULL)
    return (NULL);
  find_my_ways(courrant, data, ways);
  if ((current = ways->next) == ways)
    return (NULL);
  while (current != ways)
    {
      my_add_to_begin_room_list(current->way, courrant->ri);
      current = current->next;
    }
  return (ways);
}
