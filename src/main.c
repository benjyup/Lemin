/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin/src
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:54:13 2016 vincent mesquita
** Last update Sun Apr 24 22:33:54 2016 Vincent Florian
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"
#include "my_basics.h"

static void	free_ways(t_ways *root)
{
  t_ways	*current;
  t_ways	*tmp;

  if (!root)
    return ;
  current = root->next;
  while (current != root)
    {
      tmp = current;
      if (!current->way)
	free(current->way);
      current = current->next;
      free(tmp);
    }
  free(root);
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
  free_ways(ways);
  return (0);
}
