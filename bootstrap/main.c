/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/bootstrap
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Apr 15 19:42:03 2016 vincent mesquita
** Last update Fri Apr 15 21:03:33 2016 vincent mesquita
*/

#include <stdio.h>
#include "my.h"

int		main(void)
{
  t_maillon	*m;
  t_maillon	*m2;
  t_maillon	*m2_1;
  t_maillon	*m3;
  t_maillon	*m3_1;
  t_maillon	*m3_2;
  t_maillon	*m3_2_1;
  t_maillon	*m3_3;

  if (!(m = create_maillon(42)))
    return (-1);
  if (!(m2 = create_maillon(60012)))
    return (-1);
  if (!(m3 = create_maillon(48)))
    return (-1);
  link_maillon(m, m2);
  link_maillon(m, m3);
  if (!(m2_1 = create_maillon(30012)))
    return (-1);
  link_maillon(m2, m2_1);
  if (!(m3_1 = create_maillon(50012)))
    return (-1);
  link_maillon(m3, m3_1);
  if (!(m3_2 = create_maillon(3)))
    return (-1);
  link_maillon(m3_1, m3_2);
  if (!(m3_2_1 = create_maillon(98)))
    return (-1);
  link_maillon(m3_2, m3_2_1);
  if (!(m3_3 = create_maillon(8)))
    return (-1);
  link_maillon(m3_2, m3_3);
  print_the_graph(m);
  return (0);
}
