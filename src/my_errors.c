/*
** my_errors.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Wed Apr 20 11:43:34 2016 vincent mesquita
** Last update Sun Apr 24 15:46:28 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

static int	my_check_end_start(t_leminfo *leminfo)
{
  t_room_list	*current;
  char		stop;

  if (!leminfo || !ROOT || ROOT->next == ROOT)
    return (-1);
  current = ROOT->next;
  stop = 0;
  while (stop != -1 && current != ROOT)
    {
      if (my_strcomp(current->NAME, leminfo->start))
	stop  = ((current->LINKS == NULL) ? (-2) : (1));
      else if (my_strcomp(current->NAME, leminfo->end))
	stop  = ((current->LINKS == NULL) ? (-2) : (1));
      current = current->next;
    }
  return (stop);
}

int		my_errors(t_leminfo *leminfo, int check)
{

  if (leminfo->line == 1 && check == 0)
    return (my_puterror("Error: there is no information on stdin\n"));
  if ((!leminfo->start || !leminfo->end) && leminfo->pipe == 0 && check == 0)
    return (my_puterror2("Error: there is no start, or no end\n", LINE));
  if (my_check_end_start(leminfo) < 0)
    {
      my_puterror2("Error: ##Start or ##End have no link\n", LINE);
      return (-2);
    }
  if (leminfo->pipe == 0 && check == 0)
    return (my_puterror("Error: there is no link\n"));
  return (0);
}
