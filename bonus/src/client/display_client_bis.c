/*
** display_client_bis.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Apr 22 13:56:03 2016 Timothée Puentes
** Last update Mon Apr 25 19:01:10 2016 Timothée Puentes
*/

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
  static int		total = 0;

  pos.y = WIN_Y / 2;
  pos.x = WIN_X / 2 + data->count;
  if (data->order & O_OUT)
    display_sprite(data->pix, data->sprite, &pos, data->count);
  pos.x = -WIN_X / 2 + data->count;
  if (data->order & O_INC)
    display_sprite(data->pix, data->sprite, &pos, data->count);
  pos.y = WIN_Y / 3;
  pos.x = WIN_X / 2 - 32 * my_strlen(PRINT_START) / 2;
  if (data->start)
    my_tektext(data->pix, data->font, &pos, PRINT_START);
  if ((data->order | O_INC) != 0)
    total += 1;
  if ((data->order | O_OUT) != 0 && total != 0)
    total -= 1;
}
