/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin/src
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:54:13 2016 vincent mesquita
** Last update Thu Apr 21 12:13:35 2016 Timothée Puentes
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
  t_room_list	*way;

  if (my_parser(&leminfo) == -1)
    {
      my_putstr("Je return -1\n");
      return (0);
    }
  my_putstr("##visu\n");
  if ((way = my_path(&leminfo)) == NULL)
    return (0);
  free_leminfo(&leminfo);
  return (0);
}
