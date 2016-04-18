/*
** parser.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 02:01:14 2016 vincent mesquita
** Last update Mon Apr 18 11:34:15 2016 vincent mesquita
*/

#ifndef PARSER_H_
# define PARSER_H_
# define LINE		leminfo->line
# define MALLOC_ERR	"Error Malloc() failed\n"

typedef struct		s_position
{
  int			x;
  int			y;
}			t_position;

typedef struct		s_room_info
{
  char			*name;
  t_position		pos;
}			t_room_info;

typedef struct		s_room_list
{
  t_room_info		*ri;
  struct s_room_list	*next;
  struct s_room_list	*prev;
}			t_room_list;

typedef struct		s_leminfo
{
  unsigned int		line;
  int			ants_nbr;
  char			pipe;
  char			*start;
  char			*end;
  t_room_list		*rl_root;
}		t_leminfo;

int			my_nan(char *str);
void			free_leminfo(t_leminfo *leminfo);
void			my_epure_str(char *str);
int			there_is_dash(char *str,
				      t_leminfo *leminfo);
int			my_init_leminfo(t_leminfo *leminfo);
int			my_fill_room_list(t_leminfo *leminfo,
				  char **wordtab);
int			my_add_to_end_room_list(t_room_list *root,
						t_room_info *ri);

#endif /* !PARSER_H_ */
