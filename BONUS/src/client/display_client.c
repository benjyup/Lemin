/*
** display_client.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Apr 21 10:33:03 2016 Timothée Puentes
** Last update Fri Apr 22 11:36:26 2016 Timothée Puentes
*/

#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_basics.h"
#include "lemin.h"
#include "reseaux.h"
#include "client.h"

int			set_termios(int i)
{
  static struct termios	old;
  static struct termios	new;

  if (i == 0)
    {
      ioctl(0, TCGETS, &old);
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      ioctl(0, TCSETS, &new);
    }
  else
    ioctl(0, TCSETS, &old);
  return (0);
}

int			read_order(int sockfd)
{
  t_order		order;

  if (read(sockfd, &order, sizeof(order)) != sizeof(order))
    return (0);
  return (order.type);
}

void			print_data(t_client *data)
{
  t_bunny_position	pos;

  pos.y = WIN_Y / 2;
  pos.x = WIN_X / 2 + data->count - 32;
  if (data->order | O_INC)
    my_tektext(data->pix, data->font, &pos, "A");
  pos.x = data->count - 32;
  if (data->order | O_INC)
    my_tektext(data->pix, data->font, &pos, "A");
}

void			treat_order(t_client *data)
{
  if (data->count == 0)
    {
      if (data->order == 0)
	return ;
      data->order = data->order | read_order(data->sockfd);
    }
  if ((data->order | O_NTURN) == 1)
    {
      print_data(data);
      data->count = (data->count + 1) % (WIN_X + 32);
      if (data->count == 0)
	data->order = 0;
    }
}

t_bunny_response	mainloop(void *_data)
{
  t_bunny_position	p;
  t_client		*data;

  data = _data;
  treat_order(data);
  p.x = 0;
  p.y = 0;
  bunny_my_fill(data->pix, 0x32000000);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &p);
  bunny_display(data->win);
  return (GO_ON);
}

int		display_client(int sockfd)
{
  t_client	data;
  char		buffer[BUFF + 1];

  my_memset(buffer, BUFF, 0);
  if (read(sockfd, buffer, BUFF) < 0)
    return (my_puterror(READ_ERR));
  if (write(sockfd, buffer, BUFF) < 0)
    return (my_puterror(READ_ERR));
  if ((data.win = bunny_start(WIN_X, WIN_Y, false, buffer)) == NULL ||
      (data.pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL ||
     (data.font = bunny_load_pixelarray("font.png")) == NULL)
    return (my_puterror(MALLOC_ERR));
  bunny_set_loop_main_function(mainloop);
  data.sockfd = sockfd;
  data.count = 0;
  data.order = 0;
  set_termios(0);
  bunny_loop(data.win, 255, &data);
  set_termios(1);
  bunny_stop(data.win);
  bunny_delete_clipable(&data.pix->clipable);
  return (0);
}
