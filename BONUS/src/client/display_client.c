/*
** display_client.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Apr 21 10:33:03 2016 Timothée Puentes
** Last update Thu Apr 21 15:43:09 2016 Timothée Puentes
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
    return (-1);
  return (order.type);
}

t_bunny_response	mainloop(void *_data)
{
  t_bunny_position	p;
  t_client		*data;
  int			order;
  unsigned int		color;

  data = _data;
  if (data->count == 0)
    {
      order = read_order(data->sockfd);
      if (order != -1)
	printf("order i %i\n", order);
    }
  color = MY_B;
  if (order == O_EXIT)
    return (EXIT_ON_SUCCESS);
  else if (order == O_INC || order == O_OUT)
    data->ant = ((order == O_INC) ? (1) : (0));
  else if (order == O_NTURN)
    color = RED;
  p.x = WIN_X / 3;
  p.y = WIN_Y / 2;
  if (data->ant && !data->count)
    my_tektext(data->pix, data->font, &p, "! Ant incoming !");
  p.x = 0;
  p.y = 0;
  bunny_my_fill(data->pix, color);
  data->count = (data->count + 1) % 256;
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
    return (my_puterror(WRITE_ERR));
  if ((data.win = bunny_start(WIN_X, WIN_Y, false, buffer)) == NULL ||
      (data.pix = bunny_new_pixelarray(WIN_X, WIN_Y)) == NULL ||
      (data.font = bunny_load_pixelarray("font.png")) == NULL)
    return (my_puterror(MALLOC_ERR));
  bunny_set_loop_main_function(mainloop);
  data.sockfd = sockfd;
  data.ant = 0;
  data.count = 0;
  set_termios(0);
  bunny_loop(data.win, 255, &data);
  set_termios(1);
  bunny_stop(data.win);
  bunny_delete_clipable(&data.pix->clipable);
  return (0);
}
