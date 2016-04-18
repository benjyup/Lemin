/*
** parser.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:59:33 2016 vincent mesquita
** Last update Mon Apr 18 12:26:55 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

static int	my_start_and_end(char *str, t_leminfo *leminfo)
{
  if (!str)
    return (-1);
  if (leminfo->start_end == 0)
    {
      if (my_strcomp(str, "##start"))
	if (leminfo->start)
	  return (my_puterror2("##start already initialized\n", LINE));
      if (my_strcomp(str, "##end"))
	if (leminfo->end || !(leminfo->end = my_strcpy(str)))
	  return (my_puterror2("##end already initialized\n", LINE));
    }
  else
    {
      if (leminfo->start_end == START && !(leminfo->start = my_strcpy(str)))
	return (my_puterror(MALLOC_ERR));
      if (leminfo->start_end == END && !(leminfo->end = my_strcpy(str)))
	return (my_puterror(MALLOC_ERR));
    }
  return (0);
}

static int	my_ant_nbr(char **wordtab, t_leminfo *leminfo)
{
  if (LINE == 1)
    {
      if (my_wordtab_len(wordtab) != 1
	  || my_nan(wordtab[0])
	  || (leminfo->ants_nbr = my_getnbr(wordtab[0])) <= 0)
	return (my_puterror2("Ant number invalid\n", LINE));
    }
  return (0);
}

static int	my_rooms(t_leminfo *leminfo,
			 char *str)
{
  char		**wordtab;

  if (leminfo->pipe != 0)
    return (my_puterror2("Error: Bad format\n", LINE));
  if (!(wordtab = my_str_to_wordtab(str, ' '))
      || my_ant_nbr(wordtab, leminfo) == -1
      || my_start_and_end(wordtab[0], leminfo) == -1
      || my_fill_room_list(leminfo, wordtab))
    return (-1);
  my_free_wordtab(wordtab);
  LINE += 1;
  return (0);
}

int		my_parser(t_leminfo *leminfo)
{
  char		*str;

  if (!my_init_leminfo(leminfo))
    return (-1);
  while ((str = get_next_line(0)) != NULL)
    {
      my_epure_str(str);
      if (!there_is_dash(str, leminfo))
	{
	  if (my_rooms(leminfo, str) == -1)
	    return (-1);
	}
      else
	my_putstr("Pipe\n");
      free(str);
    }
  if (leminfo->line == 1)
    return (my_puterror2("There isn't information on stdin\n", LINE));
  free_leminfo(leminfo);
  return (0);
}
