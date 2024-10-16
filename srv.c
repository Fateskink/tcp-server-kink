/* srv.c */
#include <tcp.h>

#define PORT 8181

int main() {
  int s, c;
  socklen_t addrlen;
  struct sockaddr_in srv, cli;
  char buf[512];
  char *data;

  addrlen = 0;
  memset(&srv, 0, sizeof(srv));
  memset(&cli, 0, sizeof(cli));
  s = socket(AF_INET, SOCK_STREAM, 0);

  if (s< 0) {
    printf("socket() error\n");

    return -1;
  }

  srv.sin_family = AF_INET;
  srv.sin_addr.s_addr = 0;
  srv.sin_port = htons(PORT);

  if (bind(s, (struct sockaddr *)&srv, sizeof(srv))) {
    printf("bind() error\n");
    close(s);

    return -1;
  }

  /*
    5 : queue - number network connection this tcp server gonna keep
  */
  if (listen(s, 5)) {
    printf("listen() error\n");
    close(s);

    return -1;
  }

  printf("Listenning 0.0.0.0 : %d\n", PORT);

  c = accept(s, (struct sockaddr *)&cli, &addrlen);
  if (c < 0) {
    printf("accept() failed\n");
    close(s);

    return -1;
  }

  printf("Client connected\n");

  read(c, buf, 511);
  data = "https v1.0\n";

  write(c, data, strlen(data));

  close(c);
  close(s);

  return 0;
}
