/*
** graph.h for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Apr 18 12:00:52 2016 Timothée Puentes
** Last update Tue Apr 19 13:41:58 2016 Timothée Puentes
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# define	SUCCESS 0
# define	ERR 1
# define	PNT_ERR (void*)-1
typedef struct	s_path
{
  char		*name;
  struct s_path	*next;
}		t_path;

t_path		**find_path(t_room_list *root,
			    t_leminfo *data);
void		free_path(t_path *path);
t_path		*cpy_new_path(t_path *old,
			      char *new_name);
int		recur_path(t_path **list_path,
			   t_path *act_path,
			   t_room_list *graph_root,
			   t_leminfo *data);

void		add_path_at_end(t_path *root, t_path *new);
t_path		*create_a_path(char *str);
void		print_all_path(t_path *path);

#endif /* !GRAPH_H_ */
