/*
** my_putchar.c for my_putchar in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Nov 30 12:24:30 2015 vincent mesquita
** Last update Tue Apr 19 13:22:42 2016 vincent mesquita
*/

#include <unistd.h>

void	my_putchar(char c)
{
  if (c == 0)
    return ;
  write(1, &c, 1);
}
