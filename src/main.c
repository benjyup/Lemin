/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin/src
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:54:13 2016 vincent mesquita
** Last update Tue Apr 19 14:46:31 2016 Timothée Puentes
*/

#include <stdlib.h>
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
  int		c;
  t_path	**list;

  if (my_parser(&leminfo) == -1 ||
      (list = find_path(leminfo.rl_root, &leminfo)) == NULL)
    return (-1);
  c = 0;
  while (c < leminfo.total_link)
    {
      my_putstr("\nPath\n");
      print_all_path(list[c]);
      c += 1;
    }
  return (0);
}
