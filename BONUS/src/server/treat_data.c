/*
** treat_data.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS/server
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Apr 20 15:53:12 2016 Timothée Puentes
** Last update Thu Apr 21 16:47:19 2016 Timothée Puentes
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "reseaux.h"
#include "my_basics.h"

static int	get_rank(t_reseaux *data, char *str)
{
  unsigned int	c;
  t_room_list	*cur;

  cur = data->ROOT->next;
  c = 0;
  while (cur != data->ROOT &&
	 !my_strcomp(cur->ri->name, str) && c < TOTAL_ROOM)
    {
      cur = cur->next;
      c += 1;
    }
  if (c == TOTAL_ROOM)
    return (-my_puterror("No such Room\n"));
  return (c);
}

static int	treat_action(t_reseaux *data, char *str)
{
  char		**wordtab;
  int		c;
  int		rank;

  if ((wordtab = my_str_to_wordtab(str, '-')) == NULL)
    return (my_puterror(MALLOC_ERR));
  if (wordtab[0][0] != 'P' || wordtab[0][0] == 0)
    return (my_puterror("SYNTAX_ERR\n"));
  c = my_getnbr(&wordtab[0][1]);
  if (c > (int)TOTAL_ANT || c < 0 ||
      (rank = get_rank(data, ANTS[c])) < 0 ||
      send_order(CLIENT[rank], O_OUT, 0))
    return (my_puterror(SYNTAX_ERR));
  free(ANTS[c]);
  if ((ANTS[c] = my_strcpy(wordtab[1])) == NULL)
      return (my_puterror(MALLOC_ERR));
  if ((rank = get_rank(data, ANTS[c])) < 0 ||
      send_order(CLIENT[rank], O_INC, 0))
    return (my_puterror(SYNTAX_ERR));
  free(wordtab[0]);
  free(wordtab);
  return (0);
}

static int	treat_line(t_reseaux *data, char *str)
{
  char		**wordtab;
  unsigned int	c;

  if ((wordtab = my_str_to_wordtab(str, ' ')) == NULL)
    return (my_puterror(MALLOC_ERR));
  c = 0;
  while (wordtab[c] != NULL)
    {
      if (treat_action(data, wordtab[c]))
	return (1);
      c += 1;
    }
  my_free_wordtab(wordtab);
  sleep(2);
  if (broadcast_order(data, O_NTURN, 0) != 0)
    return (1);
  sleep(1);
  return (0);
}

int		treat_data(t_reseaux *data)
{
  char		*str;

  while ((str = get_next_line(0)) != NULL)
    {
      treat_line(data, str);
    }
  if (broadcast_order(data, O_EXIT, 0))
    return (1);
  return (0);
}
