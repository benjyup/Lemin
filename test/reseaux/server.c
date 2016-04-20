/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "reseaux.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int			read_and(int sockfd)
{
  struct sockaddr_in	cli_addr;
  int			newsockfd;
  socklen_t		clilen;
  char			buffer[256];
  int			n;

  clilen = sizeof(cli_addr);

  newsockfd = accept(sockfd,
		     (struct sockaddr *) &cli_addr,
		     &clilen);
  if (newsockfd < 0)
    error("ERROR on accept");
  my_memset(buffer, 256, 0);
  if ((n = read(newsockfd,buffer,255)) < 0)
    error("ERROR reading from socket");
  printf("%s\n",buffer);
  if ((n = write(newsockfd, "Received", 18)) < 0)
    error("ERROR writing to socket");
  close(newsockfd);

}

int			main(int argc, char *argv[])
{
  int			sockfd;
  int			portno;
  struct sockaddr_in	serv_addr;

  if (argc < 2)
    {
      fprintf(stderr,"ERROROB, no port provided\n");
      exit(1);
    }
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    return (printf("ERROR opening socket"));
  my_memset((char *) &serv_addr, sizeof(serv_addr), 0);
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = swap(portno);
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
	   sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  listen(sockfd, 5);
  printf("Server timmy.corp online\tv1.005.2\n");
  while (1)
    read_and(sockfd);
  close(sockfd);
  return 0;
}
