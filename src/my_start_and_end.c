/*
** my_start_and_end.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Apr 18 20:33:53 2016 vincent mesquita
** Last update Thu Apr 21 21:44:09 2016 vincent mesquita
*/

#include "parser.h"
#include "my_basics.h"

int		my_start_and_end2(char *str,
				  t_leminfo *leminfo)
{
  if (leminfo->start_end == START && !(leminfo->start = my_strcpy(str)))
    return (my_puterror(MALLOC_ERR));
  if (leminfo->start_end == END && !(leminfo->end = my_strcpy(str)))
    return (my_puterror(MALLOC_ERR));
  leminfo->start_end = 0;
  return (0);
}

int		my_start_and_end(char *str,
				 t_leminfo *leminfo)
{
  if (leminfo->start_end == 0 || my_strcomp(str, "##start")
      || my_strcomp(str, "##end"))
    {
      if (my_strcomp(str, "##start"))
	{
	  if (leminfo->start || leminfo->start_end != 0)
	    return (my_puterror2("##start already initialized\n",
				 LINE));
	  leminfo->start_end = START;
	}
      if (my_strcomp(str, "##end"))
	{
	  if (leminfo->end || leminfo->start_end != 0)
	    return (my_puterror2("##end already initialized\n", LINE));
	  leminfo->start_end = END;
	}
    }
  else if (!my_strcomp(str,"##start") && !my_strcomp(str,"##end"))
    if (my_start_and_end2(str, leminfo) < 0)
      return (-1);
  return (0);
}
