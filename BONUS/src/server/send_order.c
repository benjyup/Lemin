/*
** send_order.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS/server
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Apr 20 16:28:42 2016 Timothée Puentes
** Last update Fri Apr 22 11:34:48 2016 Timothée Puentes
*/

#include <unistd.h>
#include "reseaux.h"
#include "client.h"
#include "my_basics.h"

int		wait_for_next(t_reseaux *data)
{
  unsigned int	c;
  char		buff[BUFF + 1];

  c = 0;
  while (c < TOTAL_ROOM)
    {
      if (read(CLIENT[c], buff, BUFF) < 0)
	return (my_puterror(READ_ERR));
      c += 1;
    }
  return (0);
}

int		broadcast_order(t_reseaux *data, char order, int arg)
{
  unsigned int	c;
  t_order	ord;

  (void)arg;
  my_memset((char *)&ord, sizeof(ord), 0);
  ord.type = order;
  c = 0;
  while (c < TOTAL_ROOM)
    {
      if (write(CLIENT[c], (void*)&ord, sizeof(ord)) != sizeof(ord))
	return (my_puterror(WRITE_ERR));
      c += 1;
    }
  return (0);
}

int		send_order(int sockfd, char order, int data)
{
  t_order	ord;

  (void)data;
  ord.type = order;
  if (write(sockfd, (void*)&ord, sizeof(ord)) != sizeof(ord))
    return (my_puterror(WRITE_ERR));
  return (0);
}
