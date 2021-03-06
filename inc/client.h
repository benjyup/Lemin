/*
** client.h for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Apr 21 10:31:39 2016 Timothée Puentes
** Last update Sun Apr 24 22:21:56 2016 Vincent Florian
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <lapin.h>

# define		BUFF 248
# define		WIN_X 1000
# define		WIN_Y 1000
# define		SPRITE_X 352
# define		SPRITE_Y 325
# define		NB_SPRITE_X 3
# define		NB_SPRITE_Y 4
# define		MY_B 0x32000000
# define		MY_W 0x32FFFFFF
# define		ANIM_SPEED 100

typedef struct		s_client
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_bunny_pixelarray	*sprite;
  int			sockfd;
  int			count;
  int			order;
  int			start;
}			t_client;

void			my_tektext(t_bunny_pixelarray *out,
				   t_bunny_pixelarray *fontpng,
				   const t_bunny_position *pos,
				   const char *str);
void			bunny_my_fill(t_bunny_pixelarray *pix,
				      unsigned int color_ui);
int			display_client(int sockfd);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
void			tekpixel_t(t_bunny_pixelarray *pix,
				   t_bunny_position *pos,
				   t_color *color);
int			read_order(int sockfd);
int			set_termios(int i);
int			read_order(int sockfd);
void			print_data(t_client *data);
void			display_sprite(t_bunny_pixelarray *pix,
				       t_bunny_pixelarray *sprite,
				       t_bunny_position *pos,
				       int avance);

#endif /* !CLIENT_H_ */
