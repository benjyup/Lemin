/*
** print_my_move.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 24 21:05:40 2016 vincent mesquita
** Last update Sun Apr 24 21:06:39 2016 vincent mesquita
*/

#include "parser.h"
#include "my_basics.h"

void		print_my_move2(t_leminfo *data,
			       t_ways *my_way)
{
  my_putchar('P');
  my_put_nbr(data->ants_nbr);
  my_putchar('-');
  my_putstr(my_way->next->way->prev->NAME);
  my_putchar('\n');
}
