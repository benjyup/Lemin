/*
** my_put_error.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/Corewar/CPE_2015_corewar
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Mar 18 15:01:59 2016 vincent mesquita
** Last update Thu Mar 24 15:45:03 2016 Vincent Florian
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_basics.h"
#include "asm.h"

static void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

static void	my_put_nbr_error(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar_error('-');
    }
  if (nb >= 10)
    my_put_nbr_error(nb / 10);
  my_putchar_error(nb % 10 + '0');
}

void		my_put_error2(char *who,
			      int line,
			      char *filename,
			     char *error)
{
  if (who == NULL || filename == NULL || error == NULL)
    return ;
  my_puterror(who);
  my_puterror(": ");
  my_puterror("\033[1;31m");
  my_puterror("Error");
  my_puterror("\033[0m");
  my_putstr(": ");
  my_puterror(filename);
  my_putstr(", line ");
  my_put_nbr_error(line);
  my_puterror(" -> ");
  my_puterror("\033[1;36m");
  my_puterror(error);
  my_puterror("\033[0m");
}

void		my_put_error(char *who,
			     t_file_info *fi,
			     char *error)
{
  if (who == NULL || fi->filename == NULL || error == NULL)
    return ;
  my_puterror(who);
  my_puterror(": ");
  my_puterror("\033[1;31m");
  my_puterror("Error");
  my_puterror("\033[0m");
  my_putstr(": ");
  my_puterror(fi->filename);
  my_putstr(", line ");
  my_put_nbr_error(fi->line_nbr);
  my_puterror(" -> ");
  my_puterror("\033[1;36m");
  my_puterror(error);
  my_puterror("\033[0m");
}

void		my_put_warning(char *who,
			       t_file_info *fi,
			       char *error)
{
  if (who == NULL || fi->filename == NULL || error == NULL)
    return ;
  my_puterror(who);
  my_puterror(": ");
  my_puterror("\033[1;33m");
  my_puterror("Warning");
  my_puterror("\033[0m");
  my_putstr(": ");
  my_puterror(fi->filename);
  my_putstr(", line ");
  my_put_nbr_error(fi->line_nbr);
  my_puterror(" -> ");
  my_puterror("\033[1;36m");
  my_puterror(error);
  my_puterror("\033[0m");
}
