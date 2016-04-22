/*
** server.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Apr 20 15:16:12 2016 Timothée Puentes
** Last update Fri Apr 22 14:05:28 2016 Timothée Puentes
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "reseaux.h"
#include "my_basics.h"
#include "client.h"

static int		init_ants(t_reseaux *data)
{
  unsigned int		c;

  if ((ANTS = malloc(sizeof(char *) * (TOTAL_ANT + 1))) == NULL)
    return (my_puterror(MALLOC_ERR));
  c = 0;
  while (c <= TOTAL_ANT)
    {
      if ((ANTS[c] = my_strcpy(START_NAME)) == NULL)
	return (my_puterror(MALLOC_ERR));
      c += 1;
    }
  return (0);
}

static void		      print_data_connexion(struct sockaddr_in cli_addr, char *str)
{
  my_putstr("Connecting ");
  my_put_nbr((cli_addr.sin_addr.s_addr) % 256);
  my_putstr(".");
  my_put_nbr((cli_addr.sin_addr.s_addr >> 8 * 1) % 256);
  my_putstr(".");
  my_put_nbr((cli_addr.sin_addr.s_addr >> 8 * 2) % 256);
  my_putstr(".");
  my_put_nbr((cli_addr.sin_addr.s_addr >> 8 * 3) % 256);
  my_putstr(" on room ");
  my_putstr(str);
  my_putstr("\n");
}

int			etablish_new_connexion(t_reseaux *data)
{
  struct sockaddr_in	cli_addr;
  socklen_t		clilen;
  unsigned int		c;
  t_room_list		*cur;
  char			buff[BUFF + 1];

  if (init_ants(data))
    return (1);
  cur = data->ROOT->next;
  c = 0;
  while (c < TOTAL_ROOM)
    {
      if ((CLIENT[c] = accept(data->sockfd, (struct sockaddr*)(&cli_addr)
			      , &clilen)) < 0)
	return (my_puterror("ERROR on accept\n"));
      if (write(CLIENT[c], cur->ri->name, BUFF) != BUFF ||
	  write(CLIENT[c], IS_START, BUFF) != BUFF ||
	  read(CLIENT[c], buff, BUFF) < 0 || !my_strcomp(buff, cur->ri->name))
	return (my_puterror("Error while pinging\n"));
      print_data_connexion(cli_addr, cur->ri->name);
      sleep(1);
      cur = cur->next;
      c += 1;
    }
  return (0);
}

int			server(t_reseaux *data)
{
 struct sockaddr_in	serv_addr;

  if ((data->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return (my_puterror("ERROR opening socket"));
  my_memset((char *) &serv_addr, sizeof(serv_addr), 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = swap(PORT);
  if (bind(data->sockfd, (struct sockaddr *) &serv_addr,
	   sizeof(serv_addr)) < 0)
    return (my_puterror("ERROR on binding"));
  if ((data->client = malloc(sizeof(int) * TOTAL_ROOM)) == NULL)
    return (my_puterror(MALLOC_ERR));
  listen(data->sockfd, TOTAL_ROOM);
  if (etablish_new_connexion(data) ||
      treat_data(data))
    return (1);
  close(data->sockfd);
  return (0);
}

int		main(void)
{
  t_reseaux	data;
  t_leminfo	leminfo;

  if (my_parser(&leminfo) == -1)
    return (ERR);
  data.leminfo = &leminfo;
  if (server(&data) != 0)
    return (ERR);
  my_putstr("Ok\n");
  return (0);
}
