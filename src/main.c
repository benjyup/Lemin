/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin/src
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:54:13 2016 vincent mesquita
** Last update Sun Apr 24 13:52:57 2016 vincent mesquita
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"
#include "my_basics.h"

void		print_all_path(t_path *path)
{
  t_path	*cur;

  cur = path;
  while (cur != NULL)
    {
      my_putstr(cur->name);
      my_putstr("\n");
      cur = cur->next;
    }
}

int		main(void)
{
  t_leminfo	leminfo;
  t_ways	*ways;

  if (my_parser(&leminfo) == -2)
    return (0);
  if (leminfo.start != NULL && leminfo.end != NULL)
    {
      if ((ways = my_path(&leminfo)) == NULL)
	return (0);
      my_check_ways(ways);
      my_antman(ways, &leminfo);
    }
  free_leminfo(&leminfo);
  return (0);
}
