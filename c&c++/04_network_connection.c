/* This is a sample for checking network connection
 * 
 * COMPILATION: gcc 04_network_connection.c -o 04_network_connection
 *
 * REFERENCES:
 * 1. https://www.cnblogs.com/tianciliangen/p/3449575.html
 * 2. https://www.geeksforgeeks.org/socket-programming-cc/
 */
#include <stdio.h>
#include <string.h>      /* memset */
#include <sys/socket.h>  /* socket() func */
#include <arpa/inet.h>
#include <unistd.h>      /* close(socket) */

int check_net(char * ip, unsigned short port)
{
  // creating socket
  int s = socket(AF_INET, SOCK_STREAM, 0);
  //============set timeout====================
  struct timeval timeout;
  timeout.tv_sec = 5;
  timeout.tv_usec = 0;

  if (setsockopt (s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
                  sizeof(timeout)) < 0)
    printf("set sock opt receive failed\n");
  if (setsockopt (s, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,
                  sizeof(timeout)) < 0)
    printf("set sock opt send failed\n");
  //===========================================
  if(s <= 0)
  {
    perror("Socket Error");
    return -1;
  }

  // arpa/inet.h
  struct sockaddr_in addr;
  addr.sin_family = AF_INET; /* IPV4 */
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);
  memset(addr.sin_zero, 0, sizeof(addr.sin_zero));

  if( connect(s, (const struct sockaddr *) &addr, sizeof(addr) ) < 0 )
  {
    printf("Problems occurred when connecting to (%s:%d) ! Please check...\n", ip, port);
    close(s);
    return 0;
  }
  else
  {
    printf("=====Connected to internet! (%s:%d)=====\n", ip, port);
    close(s);
    return 1;
  }
}

int main()
{
  return !check_net("8.8.8.8", 53);
}

