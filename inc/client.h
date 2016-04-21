/*
** client.h for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Apr 21 10:31:39 2016 Timothée Puentes
** Last update Thu Apr 21 16:57:09 2016 Timothée Puentes
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <lapin.h>

# define	BUFF 248
# define	WIN_X 1000
# define	WIN_Y 1000

# define	MY_B 0x32000000
# define	MY_W 0x32FFFFFF

typedef struct		s_client
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  int			sockfd;
  int			ant;
  int			count;
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

#endif /* !CLIENT_H_ */
