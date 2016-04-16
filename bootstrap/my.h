/*
** my.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/bootstrap
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Apr 15 19:29:52 2016 vincent mesquita
** Last update Fri Apr 15 20:49:41 2016 vincent mesquita
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>

typedef struct		s_ways
{
  struct s_maillon	*maillon;
  struct s_ways		*next;
  struct s_ways		*prev;
}			t_ways;

typedef struct		s_maillon
{
  int			data;
  t_ways		*ways_root;
  struct s_maillon	*next;
}			t_maillon;

t_maillon	*create_maillon(int data);
void		print_maillon(t_maillon *maillon);
t_ways		*create_ways(void);
void		link_maillon(t_maillon *maillon1,
			     t_maillon *maillon2);
void		print_all_maillon(t_maillon *maillon);
void		print_the_graph(t_maillon *maillon);

#endif /* !MY_H_ */
