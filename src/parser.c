/*
** parser.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:59:33 2016 vincent mesquita
** Last update Mon Apr 25 11:10:47 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

static int	my_ant_nbr(char *str, t_leminfo *leminfo)
{
  if (LINE == 1)
    {
      if (my_nan(str)
	  || (leminfo->ants_nbr = my_getnbr(str)) <= 0)
	return (my_puterror2("Error: Ant number invalid\n", LINE));
    }
  return (0);
}

static int	my_rooms(t_leminfo *leminfo,
			 char *str,
			 int check)
{
  char		**wordtab;
  int		value;

  if (LINE == 1 || str[0] == 0 || check != 0)
    return (check);
  if (leminfo->pipe != 0)
    return (my_puterror2("Error: Bad format\n", LINE));
  value = -2;
  if (!(wordtab = my_str_to_wordtab(str, ' '))
      || (value = my_start_and_end(wordtab[0], leminfo)) < 0
      || (value = my_fill_room_list(leminfo, wordtab)) < 0)
    return (value);
  my_free_wordtab(wordtab);
  return (0);
}

static int	my_pipes(t_leminfo *leminfo,
			 char *str,
			 int check)
{
  char		**wordtab;
  char		*cpy;
  int		value;

  if (LINE == 1 || check != 0)
    return (check);
  if (!leminfo->start || !leminfo->end)
    return (my_puterror("Error: there is no start, or no end\n"));
  if (my_check_dash(str) == -1
      || !(wordtab = my_str_to_wordtab(str, '-'))
      || my_wordtab_len(wordtab) != 2)
    return (my_puterror2("Error: Bad format\n", LINE));
  if (my_strcomp(wordtab[0], wordtab[1]))
    return (0);
  if ((value = my_add_links(leminfo, wordtab)) < 0)
    return (value);
  cpy = wordtab[0];
  wordtab[0] = wordtab[1];
  wordtab[1] = cpy;
  if ((value = my_add_links(leminfo, wordtab)) < 0)
    return (value);
  my_free_wordtab(wordtab);
  return (0);
}

static void	my_print_line(char *str, int check)
{
  unsigned int	i;

  i = 0;
  if (str == NULL || !str[i] || check < 0)
    return ;
  i = 0;
  while (str[i] == ' ')
    i += 1;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  while (str[i] == ' ')
	    i += 1;
	  if (str[i])
	    my_putchar(' ');
	}
      my_putchar(str[i]);
      if (str[i])
	i += 1;
    }
  my_putchar('\n');
}

int		my_parser(t_leminfo *leminfo)
{
  char		*str;
  char		check;

  if (!my_init_leminfo(leminfo))
    return (-2);
  check = 0;
  while (check >= 0 && (str = get_next_line(0)) != NULL)
    {
      if (!is_a_comment(str))
	{
	  my_epure_str(str);
	  check = my_ant_nbr(str, leminfo);
	  if (!there_is_dash(str, leminfo))
	    check = my_rooms(leminfo, str, check);
	  else
	    check = my_pipes(leminfo, str, check);
	  LINE += 1;
	  my_print_line(str, check);
	}
      free(str);
    }
  if (my_errors(leminfo, check) == -2)
    return (-2);
  return (((check == -2) ? (-2) : (0)));
}
