/*
** parser.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 02:01:14 2016 vincent mesquita
** Last update Sun Apr 17 21:14:33 2016 vincent mesquita
*/

#ifndef PARSER_H_
# define PARSER_H_
# define LINE	leminfo->line

typedef struct	s_leminfo
{
  unsigned int	line;
  int		ants_nbr;
  char		pipe;
  char		*start;
  char		*end;
}		t_leminfo;

int		my_nan(char *str);
void		free_leminfo(t_leminfo *leminfo);
void		my_epure_str(char *str);
int		there_is_dash(char *str, t_leminfo *leminfo);
int		my_init_leminfo(t_leminfo *leminfo);
#endif /* !PARSER_H_ */
