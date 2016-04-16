/*
** etape0.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/bootstrap
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Apr 15 19:39:24 2016 vincent mesquita
** Last update Fri Apr 15 20:09:16 2016 vincent mesquita
*/

#include "my.h"

t_ways		*create_ways(void)
{
  t_ways	*ways;

  if (!(ways = malloc(sizeof(*ways))))
    return (NULL);
  ways->next = ways;
  ways->prev = ways;
}

t_maillon	*create_maillon(int data)
{
  t_maillon	*new_maillon;

  if (!(new_maillon = malloc(sizeof(*new_maillon))))
    return (NULL);
  new_maillon->data = data;
  if (!(new_maillon->ways_root = create_ways()))
    return (NULL);
  new_maillon->next = NULL;
}
