/*
** main.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin/src
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:54:13 2016 vincent mesquita
** Last update Mon Apr 18 11:02:54 2016 vincent mesquita
*/

#include "lemin.h"

int		main(void)
{
  t_leminfo	leminfo;

  if (my_parser(&leminfo) == -1)
    return (-1);
  return (0);
}
