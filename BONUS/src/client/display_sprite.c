/*
** display_sprite.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Apr 22 17:12:30 2016 Timothée Puentes
** Last update Fri Apr 22 17:39:55 2016 Timothée Puentes
*/

#include <lapin.h>
#include "client.h"

static t_color		my_get_pixel(t_bunny_pixelarray *pix,
				     t_bunny_position *pos)
{
  int			i;
  unsigned int		*pix_buff;
  t_color		color;

  pix_buff = pix->pixels;
  i = pos->y * pix->clipable.clip_width + pos->x;
  if (i >= 0 && i < pix->clipable.clip_width * pix->clipable.clip_height)
    color.full = pix_buff[i];
  return (color);
}

static void		my_bunnyblit(t_bunny_pixelarray *origin,
				     t_bunny_pixelarray *dest,
				     t_bunny_position *pos_ori,
				     t_bunny_position *pos_dest)
{
  int			width_char;
  int			height_char;
  t_color		color;

  height_char = 0;
  while (height_char++ != SPRITE_X)
    {
      width_char = 0;
      while (width_char++ != SPRITE_Y)
	{
	  color = my_get_pixel(origin, pos_ori);
	  if (color.full != (unsigned int)(BLACK))
	    tekpixel_t(dest, pos_dest, &color);
	  pos_dest->x++;
	  pos_ori->x++;
	}
      pos_ori->y += 1;
      pos_dest->y += 1;
      pos_ori->x -= SPRITE_X;
      pos_dest->x -= SPRITE_X;
    }
}

void			display_sprite(t_bunny_pixelarray *pix,
				       t_bunny_pixelarray *sprite,
				       t_bunny_position *pos,
				       int avance)
{
  t_bunny_position	spri;

  spri.x = (((avance / ANIM_SPEED) % (3 * NB_SPRITE)) * SPRITE_X;
  spri.y = (((avance / ANIM_SPEED) / (3 * NB_SPRITE)) * SPRITE_Y;
  my_bunnyblit(sprite, pix, &spri, pos);
}
