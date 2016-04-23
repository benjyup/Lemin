/*
** parser.h for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 02:01:14 2016 vincent mesquita
<<<<<<< HEAD
** Last update Sat Apr 23 13:51:35 2016 Vincent Florian
=======
** Last update Wed Apr 20 16:22:30 2016 vincent mesquita
>>>>>>> 56d471a81ae721fc3d9bbbd52ad565d36f5120b2
*/

#ifndef PARSER_H_
# define PARSER_H_
# define LINE		leminfo->line
# define MALLOC_ERR	"Error Malloc() failed\n"
# define START		1
# define END		2
# define ROOT		leminfo->rl_root
# define NAME		ri->name
# define LINKS		ri->links
# define PARC		ri->parcours
# define POIDS		ri->poids

int			my_putstr(char *str);
void			my_put_nbr(int nb);

typedef struct		s_position
{
  int			x;
  int			y;
}			t_position;

typedef struct		s_link_list
{
  struct s_room_list	*link;
  struct s_link_list	*next;
  struct s_link_list	*prev;
}			t_link_list;

typedef struct		s_room_info
{
  char			*name;
  t_position		pos;
  int			ant_num;
  int			poids;
  int			parcours;
  struct s_room_list	*antecedent;
  t_link_list		*links;
}			t_room_info;

typedef struct		s_room_list
{
  t_room_info		*ri;
  struct s_room_list	*next;
  struct s_room_list	*prev;
}			t_room_list;

typedef struct		s_ways
{
  t_room_list		*way;
  struct s_ways		*next;
  struct s_ways		*prev;
}			t_ways;

typedef struct		s_leminfo
{
  unsigned int		line;
  unsigned int		total_link;
  int			ants_nbr;
  int			start_end;
  char			pipe;
  char			*start;
  char			*end;
  t_room_list		*rl_root;
  t_room_list		*father;
}			t_leminfo;

int			solo_ants(t_ways *my_way, t_leminfo *data);
void			my_delete_list(t_ways *curr);
t_ways			*create_ways(void);
void			my_check_ways(t_ways *ways);
void			my_free_room_list(t_room_list *root);
int			my_add_to_end_ways_list(t_ways *root,
						t_room_list *ri);
t_ways			*create_ways(void);
void			free_leminfo(t_leminfo *leminfo);
int			my_add_to_begin_room_list(t_room_list *root,
						  t_room_info *ri);
int			is_a_comment(char *str);
int			my_antman(t_ways *my_way, t_leminfo *data);
int			my_errors(t_leminfo *leminfo, int check);
t_room_list		*create_rl(void);
int			my_add_links(t_leminfo *leminfo,
				     char **wordtab);
int			my_start_and_end(char *str,
					 t_leminfo *leminfo);
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
void			my_show_room_list(t_room_list *root);
t_ways			*my_path(t_leminfo *data);

#endif /* !PARSER_H_ */
