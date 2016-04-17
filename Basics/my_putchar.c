/*
** my_putchar.c for my_putchar in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Nov 30 12:24:30 2015 vincent mesquita
** Last update Mon Nov 30 12:27:26 2015 vincent mesquita
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
