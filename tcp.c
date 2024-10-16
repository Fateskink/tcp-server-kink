#include <tcp.h>

int main()
{
  int s;
  struct sockaddr_in sock;
  char buf[512];
  char *data;

  data = "HEAD / HTTP/1.0\r\n\r\n";

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0)
  {
    printf("socket() error\n");

    return -1;
  }

  sock.sin_addr.s_addr = inet_addr(IP);
  sock.sin_port = htons(PORT);
  sock.sin_family = AF_INET;

  if (connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr_in)) != 0)
  {
    printf("connect() error\n");

    return -1;
  }

  write(s, data, strlen(data));
  memset(buf, 0, 512);

  read(s, buf, 511);
  close(s);
  printf("\n%s\n", buf);

  return 0;
}
