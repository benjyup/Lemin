/*
** parser.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 01:59:33 2016 vincent mesquita
** Last update Sun Apr 17 03:30:33 2016 vincent mesquita
*/

#include <stdlib.h>
#include "parser.h"
#include "my_basics.h"

static void	my_epure_str(char *str)
{
  int		i;

  if (!str)
    return ;
  i = -1;
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
}

static int	my_rooms(t_leminfo *leminfo,
			 char **wordtab,
			 int line)
{
  if (line == 1 && (my_wordtab_len(wordtab) != 1 || my_nan(wordtab[0])))
    return (my_puterror("Error: Ant number invalid\n"));
  if (my_strcomp(wordtab[0], "##start"))
    if (leminfo->start || !(leminfo->start = my_strcpy(wordtab[0])))
      return (my_puterror("##start already initialized\n"));
  if (my_strcomp(wordtab[0], "##end"))
    if (leminfo->end || !(leminfo->end = my_strcpy(wordtab[0])))
      return (my_puterror("##end already initialized\n"));
  return (0);
}

int		my_parser(t_leminfo *leminfo)
{
  char		*str;
  int		line;
  char		**wordtab;

  line = 1;
  if (!leminfo)
    return (-1);
  leminfo->start = NULL;
  leminfo->end = NULL;
  while ((str = get_next_line(0)) != NULL)
    {
      my_epure_str(str);
      if (!(wordtab = my_str_to_wordtab(str, ' ')))
	return (-1);
      if (my_rooms(leminfo, wordtab, line++) == -1)
	return (-1);
      my_show_wordtab(wordtab);
      free(str);
    }
  if (line == 1)
    return (my_puterror("There isn't information on stdin\n"));
  free_leminfo(leminfo);
  return (0);
}
