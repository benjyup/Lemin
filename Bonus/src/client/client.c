/*
** client.c for  in /home/puente_t/rendu/CPE/CPE_2015_Lemin/BONUS
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Apr 21 10:25:32 2016 Timothée Puentes
** Last update Sun Apr 24 21:10:10 2016 Peixoto Benjamin
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "my_basics.h"
#include "reseaux.h"
#include "client.h"

struct hostent		*init_hostent(char *ip)
{
  int			c;
  struct hostent	*server;
  char			**ip_cut;

  if ((server = malloc(sizeof(*server))) == NULL ||
      (server->h_name = my_strcpy(ip)) == NULL ||
      (server->h_aliases = malloc(sizeof(char*))) == NULL ||
      (server->h_addr_list = malloc(sizeof(char*) * 2)) == NULL ||
      (server->h_addr = malloc(5)) == NULL ||
      (ip_cut = my_str_to_wordtab(ip, '.')) == NULL)
    return (NULL);
  server->h_length = 4;
  server->h_aliases[0] = NULL;
    server->h_addrtype = 2;
  c = 0;
  while (c < server->h_length)
    {
      server->h_addr[c] = my_getnbr(ip_cut[c]);
      c += 1;
    }
  server->h_addr_list[1] = NULL;
  my_free_wordtab(ip_cut);
  return (server);
}

int			main(int argc, char *argv[])
{
  int			sockfd;
  struct sockaddr_in	serv_addr;
  struct hostent	*server;

  if (argc < 2)
    return (my_puterror("usage ./client_visu hostname\n"));
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ||
      (server = init_hostent(argv[1])) == NULL)
    return (1);
  my_memset((char *)&serv_addr, sizeof(serv_addr), 0);
  serv_addr.sin_family = AF_INET;
  if (my_memcpy((char *)&serv_addr.sin_addr.s_addr,
		(char *)server->h_addr,
		server->h_length) == NULL)
    return (1);
  serv_addr.sin_port = swap(PORT);
  if (connect(sockfd, (struct sockaddr *)&serv_addr,
	      sizeof(serv_addr)) < 0)
    return (my_puterror("Error connecting\n"));
  display_client(sockfd);
  close(sockfd);
  return (0);
}
