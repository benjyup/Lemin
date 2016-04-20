#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "my_basics.h"
#include "reseaux.h"

struct hostent		*init_hostent(char *ip)
{
  int			c;
  struct hostent	*server;
  char			**ip_cut;

  if ((server = malloc(sizeof(*server))) == NULL ||
      (server->h_name = strdup(ip)) == NULL ||
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
      server->h_addr[c] = atoi(ip_cut[c]);
      c += 1;
    }
  server->h_addr_list[1] = NULL;
  return (server);
}

int			read_and(int sockfd)
{
  char			buffer[256];
  int			n;

  printf("Please enter the message: ");
  my_memset(buffer, 256, 0);
  fgets(buffer,255,stdin);
  n = write(sockfd, buffer, my_strlen(buffer));
  if (n < 0)
    return(printf("Error read\n"));
}

int			main(int argc, char *argv[])
{
  int			sockfd;
  int			portno;
  struct sockaddr_in	serv_addr;
  struct hostent	*server;
  int			c;

  if (argc < 3)
    {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      return (1);
    }
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ||
      (portno = atoi(argv[2])) < 0 ||
      (server = init_hostent(argv[1])) == NULL)
    return (1);
  c = 0;
  my_memset((char *)&serv_addr, sizeof(serv_addr), 0);
  serv_addr.sin_family = AF_INET;
  if (my_memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length) == NULL)
    return (1);
  serv_addr.sin_port = swap(portno);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    return (printf("Error connecting\n"));
  while(1)
  read_and(sockfd);
 close(sockfd);
 return (0);
}
