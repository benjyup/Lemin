/*
** my_way.c for  in /home/vincen_s/CPE_2015_Lemin
**
** Made by Vincent Florian
** Login   <vincen_s@epitech.net>
**
** Started on  Wed Apr 20 12:48:27 2016 Vincent Florian
** Last update Sun Apr 24 22:36:23 2016 Vincent Florian
*/

#include <stdlib.h>
#include "my_basics.h"
#include "parser.h"

static void	print_my_move(t_room_list *current, int *flag)
{
  my_putchar('P');
  my_put_nbr(current->ri->ant_num);
  my_putchar('-');
  my_putstr(current->next->ri->name);
  my_putchar(' ');
  *flag = 1;
}

static void	move_my_ants(t_leminfo *data, int *i,
			     t_ways *curr, int *flag)
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

static void	my_check_lenght_ways(t_ways *ways, int lenght)
{
  t_ways	*curr;
  t_room_list	*current;
  int		i;

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
  my_check_lenght_ways(ways, lenght);
}
