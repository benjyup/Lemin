/*
** parser.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 02:01:14 2016 vincent mesquita
** Last update Sun Apr 17 03:27:12 2016 vincent mesquita
*/

#ifndef PARSER_H_
# define PARSER_H_

typedef struct	s_leminfo
{
  unsigned int	ants_nbr;
  char		*start;
  char		*end;
}		t_leminfo;

int		my_nan(char *str);
void		free_leminfo(t_leminfo *leminfo);

#endif /* !PARSER_H_ */
