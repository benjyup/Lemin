/*
** etape1.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/bootstrap
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Apr 15 19:45:04 2016 vincent mesquita
** Last update Fri Apr 15 21:03:30 2016 vincent mesquita
*/

#include <stdio.h>
#include "my.h"

void		print_all_maillon(t_maillon *maillon)
{
  t_ways	*current;

  if (!maillon)
    return ;
  current = maillon->ways_root->next;
  while (current != maillon->ways_root)
    {
      printf("%d\n", current->maillon->data);
      current = current->next;
    }
}

void		print_the_graph2(t_maillon *maillon)
{
  print_maillon(maillon);
  if (maillon->ways_root->next != maillon->ways_root)
    print_the_graph2(maillon->ways_root->next->maillon);
}

void		print_the_graph(t_maillon *maillon)
{
  t_ways	*current;

  if (!maillon)
    return ;
  current = maillon->ways_root->next;
  while (current != maillon->ways_root)
    {
      print_the_graph2(current->maillon);
      current = current->next;
    }
}

void		print_maillon(t_maillon *maillon)
{
  printf("%d\n", maillon->data);
}
