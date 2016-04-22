/*
** display_client.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Apr 21 10:33:03 2016 Timothée Puentes
** Last update Fri Apr 22 14:30:36 2016 Timothée Puentes
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

void			treat_order(t_client *data)
{
  if (data->count == 0)
    data->order = data->order | read_order(data->sockfd);
  if ((data->order & O_NTURN) != 0)
    {
      print_data(data);
      data->count = (data->count + 10);
      if (data->count > (WIN_X + 32))
	{
	  data->count = 0;
	  write(data->sockfd, "ok!", BUFF);
	  data->order = 0;
	}
    }
}

t_bunny_response	mainloop(void *_data)
{
  t_bunny_position	p;
  t_client		*data;

  data = _data;
  bunny_my_fill(data->pix, 0x55000000);
  treat_order(data);
  p.x = 0;
  p.y = 0;
  bunny_blit(&data->win->buffer, &data->pix->clipable, &p);
  bunny_display(data->win);
  return (GO_ON);
}

int		init_char(t_client *data)
{
  char		buff[BUFF + 1];

  my_memset(buff, BUFF, 0);
  if (read(data->sockfd, buff, BUFF) < 0)
    return (my_puterror(READ_ERR));
  if ((data->win = bunny_start(WIN_X, WIN_Y, false, buff)) == NULL ||
      (data->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL ||
     (data->font = bunny_load_pixelarray("font.png")) == NULL)
    return (my_puterror(MALLOC_ERR));
  if (read(data->sockfd, buff, BUFF) < 0)
    return (my_puterror(READ_ERR));
  data->start = ((buff[0] == '1') ? (1) : (0));
  data->start = ((buff[0] == '2') ? (2) : (data->start));
  if (write(data->sockfd, buff, BUFF) < 0)
    return (my_puterror(READ_ERR));
  return (0);
}

int		display_client(int sockfd)
{
  t_client	data;

  data.sockfd = sockfd;
  if (init_char(&data) != 0)
    return (1);
  bunny_set_loop_main_function(mainloop);
  data.count = 0;
  data.order = 0;
  set_termios(0);
  my_putstr("GO!\n");
  bunny_loop(data.win, 255, &data);
  set_termios(1);
  bunny_stop(data.win);
  bunny_delete_clipable(&data.pix->clipable);
  return (0);
}
