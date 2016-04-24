/*
** tektext.c for d in /home/mesqui_v/rendu/Tek1/S2/Infographie/Skill_test/chatty_2020/chatty_2020
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Feb 15 15:11:08 2016 vincent mesquita
** Last update Sun Apr 24 22:42:06 2016 Vincent Florian
*/

#include <lapin.h>
#include "client.h"

static void		my_getchar(char c, t_bunny_position *pos)
{
  if (c >= 'a' && c <= 'z')
    c -= 32;
  pos->x = ((c - ' ') % 10) * 32;
  pos->y = ((c - ' ') / 10) * 32;
}

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
  while (height_char++ != 32)
    {
      width_char = 0;
      while (width_char++ != 32)
	{
	  color = my_get_pixel(origin, pos_ori);
	  if (color.full != (unsigned int)(BLACK))
	    tekpixel_t(dest, pos_dest, &color);
	  pos_dest->x++;
	  pos_ori->x++;
	}
      pos_ori->y += 1;
      pos_dest->y += 1;
      pos_ori->x -= 32;
      pos_dest->x -= 32;
    }
}

static void		tektext2(const char c,
				 t_bunny_position *pos_out,
				 const t_bunny_position *pos,
				 unsigned int *i)
{
  if (c == '\n')
    {
      pos_out->y = pos_out->y + 33;
      pos_out->x = pos->x;
      *i += 1;
    }
}

void			my_tektext(t_bunny_pixelarray *out,
				   t_bunny_pixelarray *fontpng,
				   const t_bunny_position *pos,
				   const char *str)
{
  t_bunny_position	pos_out;
  t_bunny_position	pos_out_cpy;
  t_bunny_position	pos_font;
  unsigned int		i;

  if (out == NULL || str == NULL || fontpng == NULL)
    return ;
  i = 0;
  pos_out = *pos;
  while (str[i])
    {
      tektext2(str[i], &pos_out, pos, &i);
      my_getchar(str[i], &pos_font);
      pos_out_cpy = pos_out;
      my_bunnyblit(fontpng, out, &pos_font, &pos_out_cpy);
      pos_out.x += 33;
      i = i + 1;
    }
}
